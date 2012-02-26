#include "esUtil_Lua.h"
#include "esUtil.h"
#include <stdlib.h>

typedef struct
{
	// Handle to a program object
   GLuint programObject;

   // Attribute locations
   GLint  positionLoc;
   GLint  texCoordLoc;

   // Sampler location
   GLint samplerLoc;

   // Texture handle
   GLuint textureId;

   lua_State* L;
} UserData;

///
// Create a simple 2x2 texture image with four different colors
//
GLuint CreateSimpleTexture2D( )
{
   // Texture object handle
   GLuint textureId;
   
   // 2x2 Image, 3 bytes per pixel (R, G, B)
   GLubyte pixels[4 * 3] =
   {  
      255,   0,   0, // Red
        0, 255,   0, // Green
        0,   0, 255, // Blue
      255, 255,   0  // Yellow
   };

   // Use tightly packed data
   glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );

   // Generate a texture object
   glGenTextures ( 1, &textureId );

   // Bind the texture object
   glBindTexture ( GL_TEXTURE_2D, textureId );

   // Load the texture
   glTexImage2D ( GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels );

   // Set the filtering mode
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

   return textureId;

}


///
// Initialize the shader and program object
//
int Init ( ESContext *esContext )
{
	UserData *userData = (UserData *)esContext->userData;

	
     char vShaderStr[] =  
      "attribute vec4 a_position;   \n"
      "attribute vec2 a_texCoord;   \n"
      "varying vec2 v_texCoord;     \n"
      "void main()                  \n"
      "{                            \n"
      "   gl_Position = a_position; \n"
      "   v_texCoord = a_texCoord;  \n"
      "}                            \n";
   
    char  fShaderStr[] =  
      "precision mediump float;                            \n"
      "varying vec2 v_texCoord;                            \n"
      "uniform sampler2D s_texture;                        \n"
      "void main()                                         \n"
      "{                                                   \n"
      "  gl_FragColor = texture2D( s_texture, v_texCoord );\n"
      "}                                                   \n";

   // Load the shaders and get a linked program object
   userData->programObject = esLoadProgram ( vShaderStr, fShaderStr );

   // Get the attribute locations
   userData->positionLoc = glGetAttribLocation ( userData->programObject, "a_position" );
   userData->texCoordLoc = glGetAttribLocation ( userData->programObject, "a_texCoord" );
   
   // Get the sampler location
   userData->samplerLoc = glGetUniformLocation ( userData->programObject, "s_texture" );

   // Load the texture
   userData->textureId = CreateSimpleTexture2D ();

   glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );
   return TRUE;
}

///
// Draw a triangle using the shader pair created in Init()
//
void Draw ( ESContext *esContext )
{
	glutSetWindow(instance()->getHandle());

	// Push on our error handler
	lua_getglobal(luaS, "_ALERT");
	assert(lua_isfunction(luaS,-1));

    // call _RenderCB() in Lua script and report error if not found
    lua_getglobal(luaS,"_RenderCB");
    if (lua_isfunction(luaS,-1)==0)
	{
		lua_pushliteral(luaS,"No render callback has been set (_RenderCB)");
        lua_error(luaS);
	}

	// make protected call using our error handler
    lua_pcall(luaS,0,0,-2);
	lua_pop(luaS,1); // pop off error handler
   UserData *userData = (UserData*)esContext->userData;
   GLfloat vVertices[] = { -0.5f,  0.5f, 0.0f,  // Position 0
                            0.0f,  0.0f,        // TexCoord 0 
                           -0.5f, -0.5f, 0.0f,  // Position 1
                            0.0f,  1.0f,        // TexCoord 1
                            0.5f, -0.5f, 0.0f,  // Position 2
                            1.0f,  1.0f,        // TexCoord 2
                            0.5f,  0.5f, 0.0f,  // Position 3
                            1.0f,  0.0f         // TexCoord 3
                         };
   GLushort indices[] = { 0, 1, 2, 0, 2, 3 };
      
   // Set the viewport
   glViewport ( 0, 0, esContext->width, esContext->height );
   
   // Clear the color buffer
   glClear ( GL_COLOR_BUFFER_BIT );

   // Use the program object
   glUseProgram ( userData->programObject );

   // Load the vertex position
   glVertexAttribPointer ( userData->positionLoc, 3, GL_FLOAT, 
                           GL_FALSE, 5 * sizeof(GLfloat), vVertices );
   // Load the texture coordinate
   glVertexAttribPointer ( userData->texCoordLoc, 2, GL_FLOAT,
                           GL_FALSE, 5 * sizeof(GLfloat), &vVertices[3] );

   glEnableVertexAttribArray ( userData->positionLoc );
   glEnableVertexAttribArray ( userData->texCoordLoc );

   // Bind the texture
   glActiveTexture ( GL_TEXTURE0 );
   glBindTexture ( GL_TEXTURE_2D, userData->textureId );

   // Set the sampler texture unit to 0
   glUniform1i ( userData->samplerLoc, 0 );

   glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );

   eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
}

///
// Cleanup
//
void ShutDown ( ESContext *esContext )
{
   UserData *userData = (UserData*)esContext->userData;

   // Delete texture object
   glDeleteTextures ( 1, &userData->textureId );

   // Delete program object
   glDeleteProgram ( userData->programObject );
}

int esUtilLua_Loop(lua_State * L) {
	ESContext* esContext =(ESContext*)lua_touserdata(L,lua_upvalueindex(1));
	UserData* userdata = (UserData*)esContext->userData;
	userdata->L = L;
	esRegisterDrawFunc (esContext, Draw );
   
	esMainLoop ( esContext );

	ShutDown ( esContext );
	return 0;
}


int esUtilLua_getHeight(lua_State * L) {  
	ESContext* esContext =(ESContext*)lua_touserdata(L,lua_upvalueindex(1));
	lua_pushinteger(L,esContext->height);
	return 1;
}
int esUtilLua_getWidth(lua_State * L) {  
	ESContext* esContext =(ESContext*)lua_touserdata(L,lua_upvalueindex(1));
	lua_pushinteger(L,esContext->width);
	return 1;
}
int esUtilLua_CreateWindow(lua_State * L) {
	wchar_t window_name[128];
	const char* c_name;
	ESContext* esContext =(ESContext*)lua_touserdata(L,lua_upvalueindex(1));
//	if(!esContext) { lua_pushstring(L,"Lib not loaded?"); lua_error(L); return 1; }
	int width; int height;
	
	width=	luaL_checkinteger(L,1);
	height=	luaL_checkinteger(L,2);
	c_name = luaL_optstring(L,3,"OpenGLES 2.0 Lua Test");
	
	mbstowcs(window_name,c_name,strlen(c_name));

	esInitContext ( esContext );
	esCreateWindow (esContext, window_name, width, height, ES_WINDOW_RGB );
	lua_pushinteger(L,width);
	lua_pushinteger(L,height);
	return 2;
}

static const struct luaL_Reg esUtilLib[] = {
	{ "CreateWindow", esUtilLua_CreateWindow },
	{ "Width", esUtilLua_getWidth },
	{ "Height", esUtilLua_getHeight },
	{ "StartLoop", esUtilLua_Loop },
	{ NULL, NULL }
};

int lua_esUtilLib(lua_State *L) {
	ESContext* esContext;

	luaL_newlibtable(L, esUtilLib);
	esContext =(ESContext*)lua_newuserdata(L,sizeof(ESContext));
	esContext->userData = L;
	esContext->userData = lua_newuserdata(L,sizeof(UserData));
	luaL_setfuncs(L,esUtilLib,2);
	return 1;
}
void esUtil_luaReg(lua_State *L) 
{
	luaL_requiref(L,"esUtil", lua_esUtilLib, 1);
    lua_pop(L, 1);  /* remove lib */
}
