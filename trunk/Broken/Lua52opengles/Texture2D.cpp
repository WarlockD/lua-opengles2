#include "Texture2D.h"
#include "stb_image.h"
#include <assert.h>
#include <string>
#include <map>


namespace Texture {
	typedef std::map<std::string,t_imageinfo> t_texmap;
	typedef std::map<std::string,t_imageinfo>::iterator t_texmap_iter;

	static t_texmap textures;

	void init() {}
	bool load(const char* filename, t_imageinfo& info) {
		t_imageinfo& temp = textures[filename];

		// Even if the structure exisits if tex is 0 its not loaded
		if(temp.tex) { info=temp; return true; }

		stbi_uc *data = stbi_load(filename,&temp.width,&temp.height,&temp.bbp,4);
		if(!data) { textures.erase(filename); return 0; }
		

		glPixelStorei(GL_UNPACK_ALIGNMENT,1);
		glGenTextures(1, &temp.tex);
		glBindTexture(GL_TEXTURE_2D, temp.tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)temp.width, (GLsizei)temp.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

		if(gl_debug("Could not load texture\n")) {
			glDeleteTextures(1,&temp.tex);
			temp.tex =0;
		}
		stbi_image_free(data);
		return 1;
	}
	void unload() {
		for(t_texmap_iter it = textures.begin();it!=textures.end();it++)
			if(it->second.tex) { glDeleteTextures(1,&it->second.tex); }
	}
	void reload() {
		for(t_texmap_iter it = textures.begin();it!=textures.end();it++) 
			if(!it->second.tex) { 
				stbi_uc *data = stbi_load(it->first.c_str(),&it->second.width,&it->second.height,&it->second.bbp,4);
				if(!data) { textures.erase(it->first.c_str()); continue; }
		

				glPixelStorei(GL_UNPACK_ALIGNMENT,1);
				glGenTextures(1, &it->second.tex);
				glBindTexture(GL_TEXTURE_2D, it->second.tex);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)it->second.width, (GLsizei)it->second.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

				if(gl_debug("Could not load texture\n")) {
					glDeleteTextures(1,&it->second.tex);
					it->second.tex =0;
				}
				stbi_image_free(data);
			}
	}
	
static int lua_LoadTexture(lua_State *L)
{
	const char* str = luaL_checkstring(L,1);
	if(!str)  {
		lua_pushstring(L,"No File Name");
		lua_error(L);
		return 1;
	}
	t_imageinfo info;
	if(!load(str,info)) {
		lua_pushstring(L,"File Load Error");
		lua_error(L);
		return 1;
	}
	lua_createtable(L,0,5);
	lua_pushinteger(L,info.height);
	lua_setfield(L,-2,"height");
	lua_pushinteger(L,info.width);
	lua_setfield(L,-2,"width");
	lua_pushinteger(L,info.bbp);
	lua_setfield(L,-2,"bbp");
	lua_pushinteger(L,info.tex);
	lua_setfield(L,-2,"tex");
	lua_pushstring(L,str);
	lua_setfield(L,-2,"filename");
	return 1;
}

static const struct luaL_Reg TextureLib[] = {
	{ "LoadTexture", lua_LoadTexture },
	{ NULL, NULL }
};
LUAMOD_API int lualib_Texture (lua_State *L) {
  luaL_newlib(L, TextureLib);
  //lua_pushnumber(L, PI);
  //lua_setfield(L, -2, "pi");
  //lua_pushnumber(L, HUGE_VAL);
  //lua_setfield(L, -2, "huge");
  return 1;
}
void InitLua(lua_State* L) {
    luaL_requiref(L,"Texture2D", lualib_Texture, 1);
    lua_pop(L, 1);  /* remove lib */
}


};

