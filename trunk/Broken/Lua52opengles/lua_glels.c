#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <GLES2\gl2.h>

typedef struct {
	GLenum n;
	const char* s;
} t_glconst;

const t_glconst glconst[] = {
{ GL_ES_VERSION_2_0, "GL_ES_VERSION_2_0" },
{ GL_DEPTH_BUFFER_BIT, "GL_DEPTH_BUFFER_BIT" },
{ GL_STENCIL_BUFFER_BIT, "GL_STENCIL_BUFFER_BIT" },
{ GL_COLOR_BUFFER_BIT, "GL_COLOR_BUFFER_BIT" },
{ GL_FALSE, "GL_FALSE" },
{ GL_TRUE, "GL_TRUE" },
{ GL_POINTS, "GL_POINTS" },
{ GL_LINES, "GL_LINES" },
{ GL_LINE_LOOP, "GL_LINE_LOOP" },
{ GL_LINE_STRIP, "GL_LINE_STRIP" },
{ GL_TRIANGLES, "GL_TRIANGLES" },
{ GL_TRIANGLE_STRIP, "GL_TRIANGLE_STRIP" },
{ GL_TRIANGLE_FAN, "GL_TRIANGLE_FAN" },
{ GL_ZERO, "GL_ZERO" },
{ GL_ONE, "GL_ONE" },
{ GL_SRC_COLOR, "GL_SRC_COLOR" },
{ GL_ONE_MINUS_SRC_COLOR, "GL_ONE_MINUS_SRC_COLOR" },
{ GL_SRC_ALPHA, "GL_SRC_ALPHA" },
{ GL_ONE_MINUS_SRC_ALPHA, "GL_ONE_MINUS_SRC_ALPHA" },
{ GL_DST_ALPHA, "GL_DST_ALPHA" },
{ GL_ONE_MINUS_DST_ALPHA, "GL_ONE_MINUS_DST_ALPHA" },
{ GL_DST_COLOR, "GL_DST_COLOR" },
{ GL_ONE_MINUS_DST_COLOR, "GL_ONE_MINUS_DST_COLOR" },
{ GL_SRC_ALPHA_SATURATE, "GL_SRC_ALPHA_SATURATE" },
{ GL_FUNC_ADD, "GL_FUNC_ADD" },
{ GL_BLEND_EQUATION, "GL_BLEND_EQUATION" },
{ GL_BLEND_EQUATION_RGB, "GL_BLEND_EQUATION_RGB" },
{ GL_BLEND_EQUATION_ALPHA, "GL_BLEND_EQUATION_ALPHA" },
{ GL_FUNC_SUBTRACT, "GL_FUNC_SUBTRACT" },
{ GL_FUNC_REVERSE_SUBTRACT, "GL_FUNC_REVERSE_SUBTRACT" },
{ GL_BLEND_DST_RGB, "GL_BLEND_DST_RGB" },
{ GL_BLEND_SRC_RGB, "GL_BLEND_SRC_RGB" },
{ GL_BLEND_DST_ALPHA, "GL_BLEND_DST_ALPHA" },
{ GL_BLEND_SRC_ALPHA, "GL_BLEND_SRC_ALPHA" },
{ GL_CONSTANT_COLOR, "GL_CONSTANT_COLOR" },
{ GL_ONE_MINUS_CONSTANT_COLOR, "GL_ONE_MINUS_CONSTANT_COLOR" },
{ GL_CONSTANT_ALPHA, "GL_CONSTANT_ALPHA" },
{ GL_ONE_MINUS_CONSTANT_ALPHA, "GL_ONE_MINUS_CONSTANT_ALPHA" },
{ GL_BLEND_COLOR, "GL_BLEND_COLOR" },
{ GL_ARRAY_BUFFER, "GL_ARRAY_BUFFER" },
{ GL_ELEMENT_ARRAY_BUFFER, "GL_ELEMENT_ARRAY_BUFFER" },
{ GL_ARRAY_BUFFER_BINDING, "GL_ARRAY_BUFFER_BINDING" },
{ GL_ELEMENT_ARRAY_BUFFER_BINDING, "GL_ELEMENT_ARRAY_BUFFER_BINDING" },
{ GL_STREAM_DRAW, "GL_STREAM_DRAW" },
{ GL_STATIC_DRAW, "GL_STATIC_DRAW" },
{ GL_DYNAMIC_DRAW, "GL_DYNAMIC_DRAW" },
{ GL_BUFFER_SIZE, "GL_BUFFER_SIZE" },
{ GL_BUFFER_USAGE, "GL_BUFFER_USAGE" },
{ GL_CURRENT_VERTEX_ATTRIB, "GL_CURRENT_VERTEX_ATTRIB" },
{ GL_FRONT, "GL_FRONT" },
{ GL_BACK, "GL_BACK" },
{ GL_FRONT_AND_BACK, "GL_FRONT_AND_BACK" },
{ GL_TEXTURE_2D, "GL_TEXTURE_2D" },
{ GL_CULL_FACE, "GL_CULL_FACE" },
{ GL_BLEND, "GL_BLEND" },
{ GL_DITHER, "GL_DITHER" },
{ GL_STENCIL_TEST, "GL_STENCIL_TEST" },
{ GL_DEPTH_TEST, "GL_DEPTH_TEST" },
{ GL_SCISSOR_TEST, "GL_SCISSOR_TEST" },
{ GL_POLYGON_OFFSET_FILL, "GL_POLYGON_OFFSET_FILL" },
{ GL_SAMPLE_ALPHA_TO_COVERAGE, "GL_SAMPLE_ALPHA_TO_COVERAGE" },
{ GL_SAMPLE_COVERAGE, "GL_SAMPLE_COVERAGE" },
{ GL_NO_ERROR, "GL_NO_ERROR" },
{ GL_INVALID_ENUM, "GL_INVALID_ENUM" },
{ GL_INVALID_VALUE, "GL_INVALID_VALUE" },
{ GL_INVALID_OPERATION, "GL_INVALID_OPERATION" },
{ GL_OUT_OF_MEMORY, "GL_OUT_OF_MEMORY" },
{ GL_CW, "GL_CW" },
{ GL_CCW, "GL_CCW" },
{ GL_LINE_WIDTH, "GL_LINE_WIDTH" },
{ GL_ALIASED_POINT_SIZE_RANGE, "GL_ALIASED_POINT_SIZE_RANGE" },
{ GL_ALIASED_LINE_WIDTH_RANGE, "GL_ALIASED_LINE_WIDTH_RANGE" },
{ GL_CULL_FACE_MODE, "GL_CULL_FACE_MODE" },
{ GL_FRONT_FACE, "GL_FRONT_FACE" },
{ GL_DEPTH_RANGE, "GL_DEPTH_RANGE" },
{ GL_DEPTH_WRITEMASK, "GL_DEPTH_WRITEMASK" },
{ GL_DEPTH_CLEAR_VALUE, "GL_DEPTH_CLEAR_VALUE" },
{ GL_DEPTH_FUNC, "GL_DEPTH_FUNC" },
{ GL_STENCIL_CLEAR_VALUE, "GL_STENCIL_CLEAR_VALUE" },
{ GL_STENCIL_FUNC, "GL_STENCIL_FUNC" },
{ GL_STENCIL_FAIL, "GL_STENCIL_FAIL" },
{ GL_STENCIL_PASS_DEPTH_FAIL, "GL_STENCIL_PASS_DEPTH_FAIL" },
{ GL_STENCIL_PASS_DEPTH_PASS, "GL_STENCIL_PASS_DEPTH_PASS" },
{ GL_STENCIL_REF, "GL_STENCIL_REF" },
{ GL_STENCIL_VALUE_MASK, "GL_STENCIL_VALUE_MASK" },
{ GL_STENCIL_WRITEMASK, "GL_STENCIL_WRITEMASK" },
{ GL_STENCIL_BACK_FUNC, "GL_STENCIL_BACK_FUNC" },
{ GL_STENCIL_BACK_FAIL, "GL_STENCIL_BACK_FAIL" },
{ GL_STENCIL_BACK_PASS_DEPTH_FAIL, "GL_STENCIL_BACK_PASS_DEPTH_FAIL" },
{ GL_STENCIL_BACK_PASS_DEPTH_PASS, "GL_STENCIL_BACK_PASS_DEPTH_PASS" },
{ GL_STENCIL_BACK_REF, "GL_STENCIL_BACK_REF" },
{ GL_STENCIL_BACK_VALUE_MASK, "GL_STENCIL_BACK_VALUE_MASK" },
{ GL_STENCIL_BACK_WRITEMASK, "GL_STENCIL_BACK_WRITEMASK" },
{ GL_VIEWPORT, "GL_VIEWPORT" },
{ GL_SCISSOR_BOX, "GL_SCISSOR_BOX" },
{ GL_COLOR_CLEAR_VALUE, "GL_COLOR_CLEAR_VALUE" },
{ GL_COLOR_WRITEMASK, "GL_COLOR_WRITEMASK" },
{ GL_UNPACK_ALIGNMENT, "GL_UNPACK_ALIGNMENT" },
{ GL_PACK_ALIGNMENT, "GL_PACK_ALIGNMENT" },
{ GL_MAX_TEXTURE_SIZE, "GL_MAX_TEXTURE_SIZE" },
{ GL_MAX_VIEWPORT_DIMS, "GL_MAX_VIEWPORT_DIMS" },
{ GL_SUBPIXEL_BITS, "GL_SUBPIXEL_BITS" },
{ GL_RED_BITS, "GL_RED_BITS" },
{ GL_GREEN_BITS, "GL_GREEN_BITS" },
{ GL_BLUE_BITS, "GL_BLUE_BITS" },
{ GL_ALPHA_BITS, "GL_ALPHA_BITS" },
{ GL_DEPTH_BITS, "GL_DEPTH_BITS" },
{ GL_STENCIL_BITS, "GL_STENCIL_BITS" },
{ GL_POLYGON_OFFSET_UNITS, "GL_POLYGON_OFFSET_UNITS" },
{ GL_POLYGON_OFFSET_FACTOR, "GL_POLYGON_OFFSET_FACTOR" },
{ GL_TEXTURE_BINDING_2D, "GL_TEXTURE_BINDING_2D" },
{ GL_SAMPLE_BUFFERS, "GL_SAMPLE_BUFFERS" },
{ GL_SAMPLES, "GL_SAMPLES" },
{ GL_SAMPLE_COVERAGE_VALUE, "GL_SAMPLE_COVERAGE_VALUE" },
{ GL_SAMPLE_COVERAGE_INVERT, "GL_SAMPLE_COVERAGE_INVERT" },
{ GL_NUM_COMPRESSED_TEXTURE_FORMATS, "GL_NUM_COMPRESSED_TEXTURE_FORMATS" },
{ GL_COMPRESSED_TEXTURE_FORMATS, "GL_COMPRESSED_TEXTURE_FORMATS" },
{ GL_DONT_CARE, "GL_DONT_CARE" },
{ GL_FASTEST, "GL_FASTEST" },
{ GL_NICEST, "GL_NICEST" },
{ GL_GENERATE_MIPMAP_HINT, "GL_GENERATE_MIPMAP_HINT" },
{ GL_BYTE, "GL_BYTE" },
{ GL_UNSIGNED_BYTE, "GL_UNSIGNED_BYTE" },
{ GL_SHORT, "GL_SHORT" },
{ GL_UNSIGNED_SHORT, "GL_UNSIGNED_SHORT" },
{ GL_INT, "GL_INT" },
{ GL_UNSIGNED_INT, "GL_UNSIGNED_INT" },
{ GL_FLOAT, "GL_FLOAT" },
{ GL_FIXED, "GL_FIXED" },
{ GL_DEPTH_COMPONENT, "GL_DEPTH_COMPONENT" },
{ GL_ALPHA, "GL_ALPHA" },
{ GL_RGB, "GL_RGB" },
{ GL_RGBA, "GL_RGBA" },
{ GL_LUMINANCE, "GL_LUMINANCE" },
{ GL_LUMINANCE_ALPHA, "GL_LUMINANCE_ALPHA" },
{ GL_UNSIGNED_SHORT_4_4_4_4, "GL_UNSIGNED_SHORT_4_4_4_4" },
{ GL_UNSIGNED_SHORT_5_5_5_1, "GL_UNSIGNED_SHORT_5_5_5_1" },
{ GL_UNSIGNED_SHORT_5_6_5, "GL_UNSIGNED_SHORT_5_6_5" },
{ GL_FRAGMENT_SHADER, "GL_FRAGMENT_SHADER" },
{ GL_VERTEX_SHADER, "GL_VERTEX_SHADER" },
{ GL_MAX_VERTEX_ATTRIBS, "GL_MAX_VERTEX_ATTRIBS" },
{ GL_MAX_VERTEX_UNIFORM_VECTORS, "GL_MAX_VERTEX_UNIFORM_VECTORS" },
{ GL_MAX_VARYING_VECTORS, "GL_MAX_VARYING_VECTORS" },
{ GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS" },
{ GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS" },
{ GL_MAX_TEXTURE_IMAGE_UNITS, "GL_MAX_TEXTURE_IMAGE_UNITS" },
{ GL_MAX_FRAGMENT_UNIFORM_VECTORS, "GL_MAX_FRAGMENT_UNIFORM_VECTORS" },
{ GL_SHADER_TYPE, "GL_SHADER_TYPE" },
{ GL_DELETE_STATUS, "GL_DELETE_STATUS" },
{ GL_LINK_STATUS, "GL_LINK_STATUS" },
{ GL_VALIDATE_STATUS, "GL_VALIDATE_STATUS" },
{ GL_ATTACHED_SHADERS, "GL_ATTACHED_SHADERS" },
{ GL_ACTIVE_UNIFORMS, "GL_ACTIVE_UNIFORMS" },
{ GL_ACTIVE_UNIFORM_MAX_LENGTH, "GL_ACTIVE_UNIFORM_MAX_LENGTH" },
{ GL_ACTIVE_ATTRIBUTES, "GL_ACTIVE_ATTRIBUTES" },
{ GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, "GL_ACTIVE_ATTRIBUTE_MAX_LENGTH" },
{ GL_SHADING_LANGUAGE_VERSION, "GL_SHADING_LANGUAGE_VERSION" },
{ GL_CURRENT_PROGRAM, "GL_CURRENT_PROGRAM" },
{ GL_NEVER, "GL_NEVER" },
{ GL_LESS, "GL_LESS" },
{ GL_EQUAL, "GL_EQUAL" },
{ GL_LEQUAL, "GL_LEQUAL" },
{ GL_GREATER, "GL_GREATER" },
{ GL_NOTEQUAL, "GL_NOTEQUAL" },
{ GL_GEQUAL, "GL_GEQUAL" },
{ GL_ALWAYS, "GL_ALWAYS" },
{ GL_KEEP, "GL_KEEP" },
{ GL_REPLACE, "GL_REPLACE" },
{ GL_INCR, "GL_INCR" },
{ GL_DECR, "GL_DECR" },
{ GL_INVERT, "GL_INVERT" },
{ GL_INCR_WRAP, "GL_INCR_WRAP" },
{ GL_DECR_WRAP, "GL_DECR_WRAP" },
{ GL_VENDOR, "GL_VENDOR" },
{ GL_RENDERER, "GL_RENDERER" },
{ GL_VERSION, "GL_VERSION" },
{ GL_EXTENSIONS, "GL_EXTENSIONS" },
{ GL_NEAREST, "GL_NEAREST" },
{ GL_LINEAR, "GL_LINEAR" },
{ GL_NEAREST_MIPMAP_NEAREST, "GL_NEAREST_MIPMAP_NEAREST" },
{ GL_LINEAR_MIPMAP_NEAREST, "GL_LINEAR_MIPMAP_NEAREST" },
{ GL_NEAREST_MIPMAP_LINEAR, "GL_NEAREST_MIPMAP_LINEAR" },
{ GL_LINEAR_MIPMAP_LINEAR, "GL_LINEAR_MIPMAP_LINEAR" },
{ GL_TEXTURE_MAG_FILTER, "GL_TEXTURE_MAG_FILTER" },
{ GL_TEXTURE_MIN_FILTER, "GL_TEXTURE_MIN_FILTER" },
{ GL_TEXTURE_WRAP_S, "GL_TEXTURE_WRAP_S" },
{ GL_TEXTURE_WRAP_T, "GL_TEXTURE_WRAP_T" },
{ GL_TEXTURE, "GL_TEXTURE" },
{ GL_TEXTURE_CUBE_MAP, "GL_TEXTURE_CUBE_MAP" },
{ GL_TEXTURE_BINDING_CUBE_MAP, "GL_TEXTURE_BINDING_CUBE_MAP" },
{ GL_TEXTURE_CUBE_MAP_POSITIVE_X, "GL_TEXTURE_CUBE_MAP_POSITIVE_X" },
{ GL_TEXTURE_CUBE_MAP_NEGATIVE_X, "GL_TEXTURE_CUBE_MAP_NEGATIVE_X" },
{ GL_TEXTURE_CUBE_MAP_POSITIVE_Y, "GL_TEXTURE_CUBE_MAP_POSITIVE_Y" },
{ GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y" },
{ GL_TEXTURE_CUBE_MAP_POSITIVE_Z, "GL_TEXTURE_CUBE_MAP_POSITIVE_Z" },
{ GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z" },
{ GL_MAX_CUBE_MAP_TEXTURE_SIZE, "GL_MAX_CUBE_MAP_TEXTURE_SIZE" },
{ GL_TEXTURE0, "GL_TEXTURE0" },
{ GL_TEXTURE1, "GL_TEXTURE1" },
{ GL_TEXTURE2, "GL_TEXTURE2" },
{ GL_TEXTURE3, "GL_TEXTURE3" },
{ GL_TEXTURE4, "GL_TEXTURE4" },
{ GL_TEXTURE5, "GL_TEXTURE5" },
{ GL_TEXTURE6, "GL_TEXTURE6" },
{ GL_TEXTURE7, "GL_TEXTURE7" },
{ GL_TEXTURE8, "GL_TEXTURE8" },
{ GL_TEXTURE9, "GL_TEXTURE9" },
{ GL_TEXTURE10, "GL_TEXTURE10" },
{ GL_TEXTURE11, "GL_TEXTURE11" },
{ GL_TEXTURE12, "GL_TEXTURE12" },
{ GL_TEXTURE13, "GL_TEXTURE13" },
{ GL_TEXTURE14, "GL_TEXTURE14" },
{ GL_TEXTURE15, "GL_TEXTURE15" },
{ GL_TEXTURE16, "GL_TEXTURE16" },
{ GL_TEXTURE17, "GL_TEXTURE17" },
{ GL_TEXTURE18, "GL_TEXTURE18" },
{ GL_TEXTURE19, "GL_TEXTURE19" },
{ GL_TEXTURE20, "GL_TEXTURE20" },
{ GL_TEXTURE21, "GL_TEXTURE21" },
{ GL_TEXTURE22, "GL_TEXTURE22" },
{ GL_TEXTURE23, "GL_TEXTURE23" },
{ GL_TEXTURE24, "GL_TEXTURE24" },
{ GL_TEXTURE25, "GL_TEXTURE25" },
{ GL_TEXTURE26, "GL_TEXTURE26" },
{ GL_TEXTURE27, "GL_TEXTURE27" },
{ GL_TEXTURE28, "GL_TEXTURE28" },
{ GL_TEXTURE29, "GL_TEXTURE29" },
{ GL_TEXTURE30, "GL_TEXTURE30" },
{ GL_TEXTURE31, "GL_TEXTURE31" },
{ GL_ACTIVE_TEXTURE, "GL_ACTIVE_TEXTURE" },
{ GL_REPEAT, "GL_REPEAT" },
{ GL_CLAMP_TO_EDGE, "GL_CLAMP_TO_EDGE" },
{ GL_MIRRORED_REPEAT, "GL_MIRRORED_REPEAT" },
{ GL_FLOAT_VEC2, "GL_FLOAT_VEC2" },
{ GL_FLOAT_VEC3, "GL_FLOAT_VEC3" },
{ GL_FLOAT_VEC4, "GL_FLOAT_VEC4" },
{ GL_INT_VEC2, "GL_INT_VEC2" },
{ GL_INT_VEC3, "GL_INT_VEC3" },
{ GL_INT_VEC4, "GL_INT_VEC4" },
{ GL_BOOL, "GL_BOOL" },
{ GL_BOOL_VEC2, "GL_BOOL_VEC2" },
{ GL_BOOL_VEC3, "GL_BOOL_VEC3" },
{ GL_BOOL_VEC4, "GL_BOOL_VEC4" },
{ GL_FLOAT_MAT2, "GL_FLOAT_MAT2" },
{ GL_FLOAT_MAT3, "GL_FLOAT_MAT3" },
{ GL_FLOAT_MAT4, "GL_FLOAT_MAT4" },
{ GL_SAMPLER_2D, "GL_SAMPLER_2D" },
{ GL_SAMPLER_CUBE, "GL_SAMPLER_CUBE" },
{ GL_VERTEX_ATTRIB_ARRAY_ENABLED, "GL_VERTEX_ATTRIB_ARRAY_ENABLED" },
{ GL_VERTEX_ATTRIB_ARRAY_SIZE, "GL_VERTEX_ATTRIB_ARRAY_SIZE" },
{ GL_VERTEX_ATTRIB_ARRAY_STRIDE, "GL_VERTEX_ATTRIB_ARRAY_STRIDE" },
{ GL_VERTEX_ATTRIB_ARRAY_TYPE, "GL_VERTEX_ATTRIB_ARRAY_TYPE" },
{ GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED" },
{ GL_VERTEX_ATTRIB_ARRAY_POINTER, "GL_VERTEX_ATTRIB_ARRAY_POINTER" },
{ GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING, "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING" },
{ GL_IMPLEMENTATION_COLOR_READ_TYPE, "GL_IMPLEMENTATION_COLOR_READ_TYPE" },
{ GL_IMPLEMENTATION_COLOR_READ_FORMAT, "GL_IMPLEMENTATION_COLOR_READ_FORMAT" },
{ GL_COMPILE_STATUS, "GL_COMPILE_STATUS" },
{ GL_INFO_LOG_LENGTH, "GL_INFO_LOG_LENGTH" },
{ GL_SHADER_SOURCE_LENGTH, "GL_SHADER_SOURCE_LENGTH" },
{ GL_SHADER_COMPILER, "GL_SHADER_COMPILER" },
{ GL_SHADER_BINARY_FORMATS, "GL_SHADER_BINARY_FORMATS" },
{ GL_NUM_SHADER_BINARY_FORMATS, "GL_NUM_SHADER_BINARY_FORMATS" },
{ GL_LOW_FLOAT, "GL_LOW_FLOAT" },
{ GL_MEDIUM_FLOAT, "GL_MEDIUM_FLOAT" },
{ GL_HIGH_FLOAT, "GL_HIGH_FLOAT" },
{ GL_LOW_INT, "GL_LOW_INT" },
{ GL_MEDIUM_INT, "GL_MEDIUM_INT" },
{ GL_HIGH_INT, "GL_HIGH_INT" },
{ GL_FRAMEBUFFER, "GL_FRAMEBUFFER" },
{ GL_RENDERBUFFER, "GL_RENDERBUFFER" },
{ GL_RGBA4, "GL_RGBA4" },
{ GL_RGB5_A1, "GL_RGB5_A1" },
{ GL_RGB565, "GL_RGB565" },
{ GL_DEPTH_COMPONENT16, "GL_DEPTH_COMPONENT16" },
{ GL_STENCIL_INDEX, "GL_STENCIL_INDEX" },
{ GL_STENCIL_INDEX8, "GL_STENCIL_INDEX8" },
{ GL_RENDERBUFFER_WIDTH, "GL_RENDERBUFFER_WIDTH" },
{ GL_RENDERBUFFER_HEIGHT, "GL_RENDERBUFFER_HEIGHT" },
{ GL_RENDERBUFFER_INTERNAL_FORMAT, "GL_RENDERBUFFER_INTERNAL_FORMAT" },
{ GL_RENDERBUFFER_RED_SIZE, "GL_RENDERBUFFER_RED_SIZE" },
{ GL_RENDERBUFFER_GREEN_SIZE, "GL_RENDERBUFFER_GREEN_SIZE" },
{ GL_RENDERBUFFER_BLUE_SIZE, "GL_RENDERBUFFER_BLUE_SIZE" },
{ GL_RENDERBUFFER_ALPHA_SIZE, "GL_RENDERBUFFER_ALPHA_SIZE" },
{ GL_RENDERBUFFER_DEPTH_SIZE, "GL_RENDERBUFFER_DEPTH_SIZE" },
{ GL_RENDERBUFFER_STENCIL_SIZE, "GL_RENDERBUFFER_STENCIL_SIZE" },
{ GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE, "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE" },
{ GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME" },
{ GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL, "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL" },
{ GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE, "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE" },
{ GL_COLOR_ATTACHMENT0, "GL_COLOR_ATTACHMENT0" },
{ GL_DEPTH_ATTACHMENT, "GL_DEPTH_ATTACHMENT" },
{ GL_STENCIL_ATTACHMENT, "GL_STENCIL_ATTACHMENT" },
{ GL_NONE, "GL_NONE" },
{ GL_FRAMEBUFFER_COMPLETE, "GL_FRAMEBUFFER_COMPLETE" },
{ GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT, "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT" },
{ GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT, "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT" },
{ GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS, "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS" },
{ GL_FRAMEBUFFER_UNSUPPORTED, "GL_FRAMEBUFFER_UNSUPPORTED" },
{ GL_FRAMEBUFFER_BINDING, "GL_FRAMEBUFFER_BINDING" },
{ GL_RENDERBUFFER_BINDING, "GL_RENDERBUFFER_BINDING" },
{ GL_MAX_RENDERBUFFER_SIZE, "GL_MAX_RENDERBUFFER_SIZE" },
{ GL_INVALID_FRAMEBUFFER_OPERATION, "GL_INVALID_FRAMEBUFFER_OPERATION" },
{ NULL, NULL }
};
#define LUA_GL_ERROR() return 0;
#define LUA_GL_EXTRA_RTN() return 1;

 int lua_glCheckFramebufferStatus(lua_State* L)	{ lua_pushunsigned(L,glCheckFramebufferStatus(luaL_checkunsigned(L,1))); LUA_GL_EXTRA_RTN() }
 int lua_glHint(lua_State* L)					{ glHint(luaL_checkunsigned(L,1), luaL_checkunsigned(L,2)); LUA_GL_ERROR() }
 

 int lua_glIsBuffer (lua_State* L)				{ lua_pushboolean(L,glIsBuffer (luaL_checkunsigned(L,1))); LUA_GL_EXTRA_RTN() }
 int lua_glIsEnabled (lua_State* L)				{ lua_pushboolean(L,glIsEnabled (luaL_checkunsigned(L,1))); LUA_GL_EXTRA_RTN() }
 int lua_glIsFramebuffer (lua_State* L)			{ lua_pushboolean(L,glIsFramebuffer (luaL_checkunsigned(L,1))); LUA_GL_EXTRA_RTN() }

 int lua_glIsRenderbuffer (lua_State* L)		{ lua_pushboolean(L,glIsRenderbuffer (luaL_checkunsigned(L,1))); LUA_GL_EXTRA_RTN() }
 
 int lua_glIsTexture (lua_State* L)				{ lua_pushboolean(L,glIsTexture (luaL_checkunsigned(L,1))); LUA_GL_EXTRA_RTN() }

 int lua_glCreateShader(lua_State* L)			{  lua_pushunsigned(L,glCreateShader(luaL_checkunsigned(L,1))); LUA_GL_EXTRA_RTN() }


 int lua_glActiveTexture(lua_State* L)			{  glActiveTexture(	luaL_checkunsigned(L,1));			LUA_GL_ERROR() }
 int lua_glClear(lua_State* L)					{  glClear(			luaL_checkunsigned(L,1));			LUA_GL_ERROR() }
 int lua_glBlendEquation(lua_State* L)			{  glBlendEquation(	luaL_checkunsigned(L,1));			LUA_GL_ERROR() }

 int lua_glClearStencil(lua_State* L)			{  glClearStencil(	luaL_checkinteger(L,1));			LUA_GL_ERROR() }
 int lua_glClearDepthf(lua_State* L)			{  glClearDepthf(	(float)luaL_checknumber(L,1));	LUA_GL_ERROR() }

 int lua_glIsShader (lua_State* L)				{ lua_pushboolean(L,glIsShader (luaL_checkunsigned(L,1))); LUA_GL_EXTRA_RTN() }
 int lua_glIsProgram (lua_State* L)				{ lua_pushboolean(L,glIsProgram (luaL_checkunsigned(L,1))); LUA_GL_EXTRA_RTN() }
 int lua_glCompileShader(lua_State* L)			{  glCompileShader(	luaL_checkunsigned(L,1));			LUA_GL_ERROR() }
 int lua_glAttachShader(lua_State* L)			{  glAttachShader(			luaL_checkunsigned(L,1), luaL_checkunsigned(L,2)); LUA_GL_ERROR() }
 int lua_glCreateProgram(lua_State* L)			{  lua_pushunsigned(L,glCreateProgram ()); LUA_GL_EXTRA_RTN() }
 int lua_glDeleteProgram(lua_State* L)			{  glDeleteProgram(luaL_checkunsigned(L,1)); LUA_GL_ERROR() }
 int lua_glDeleteShader(lua_State* L)			{  glDeleteShader(luaL_checkunsigned(L,1)); LUA_GL_ERROR() }
 int lua_glDetachShader(lua_State* L) { int p=1; glDetachShader(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glLinkProgram(lua_State* L) { int p=1; glLinkProgram(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glGetProgramiv(lua_State* L) { int p=1; glGetProgramiv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLint* params); LUA_GL_ERROR() }
 int lua_glGetProgramInfoLog(lua_State* L) { int p=1; glGetProgramInfoLog(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), GLsizei* length, GLchar* infolog); LUA_GL_ERROR() }
 int lua_glGetShaderiv(lua_State* L) { int p=1; glGetShaderiv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLint* params); LUA_GL_ERROR() }
 int lua_glGetShaderInfoLog(lua_State* L) { int p=1; glGetShaderInfoLog(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), GLsizei* length, GLchar* infolog); LUA_GL_ERROR() }
  int lua_glGetAttachedShaders(lua_State* L) { int p=1; glGetAttachedShaders(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), GLsizei* count, GLuint* shaders); LUA_GL_ERROR() }
  int lua_glShaderBinary(lua_State* L) { int p=1; glShaderBinary(luaL_checkinteger(L,p++), const GLuint* shaders, luaL_checkunsigned(L,p++), const GLvoid* binary, luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
 int lua_glShaderSource(lua_State* L) { int p=1; glShaderSource(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), const GLchar** string, const GLint* length); LUA_GL_ERROR() }
 int lua_glGetShaderPrecisionFormat(lua_State* L) { int p=1; glGetShaderPrecisionFormat(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLint* range, GLint* precision); LUA_GL_ERROR() }
 int lua_glGetShaderSource(lua_State* L) { int p=1; glGetShaderSource(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), GLsizei* length, GLchar* source); LUA_GL_ERROR() }


 int lua_glGetAttribLocation(lua_State* L)      {  lua_pushinteger(L,glGetAttribLocation(luaL_checkunsigned(L,1), luaL_checkstring(L,2))); LUA_GL_EXTRA_RTN() }


 int lua_glBindBuffer(lua_State* L)				{  glBindBuffer(			luaL_checkunsigned(L,1), luaL_checkunsigned(L,2)); LUA_GL_ERROR() }
 int lua_glBindFramebuffer(lua_State* L)		{  glBindFramebuffer(		luaL_checkunsigned(L,1), luaL_checkunsigned(L,2)); LUA_GL_ERROR() }
 int lua_glBindRenderbuffer(lua_State* L)		{  glBindRenderbuffer(		luaL_checkunsigned(L,1), luaL_checkunsigned(L,2)); LUA_GL_ERROR() }
 int lua_glBindTexture(lua_State* L)			{  glBindTexture(			luaL_checkunsigned(L,1), luaL_checkunsigned(L,2)); LUA_GL_ERROR() }
 int lua_glBlendEquationSeparate(lua_State* L)	{  glBlendEquationSeparate(	luaL_checkunsigned(L,1), luaL_checkunsigned(L,2)); LUA_GL_ERROR() }
 int lua_glBlendFunc(lua_State* L)				{  glBlendFunc(				luaL_checkunsigned(L,1), luaL_checkunsigned(L,2)); LUA_GL_ERROR() }

 int lua_glBindAttribLocation(lua_State* L)		{  glBindAttribLocation(	luaL_checkunsigned(L,1), luaL_checkunsigned(L,2), luaL_checkstring(L,3)); LUA_GL_ERROR() }

 int lua_glClearColor(lua_State* L)				{  glClearColor(	(float)luaL_checknumber(L,1), (float)luaL_checknumber(L,2), (float)luaL_checknumber(L,3), (float)luaL_checknumber(L,4)); LUA_GL_ERROR() }
 int lua_glBlendColor(lua_State* L)				{  glBlendColor(	(float)luaL_checknumber(L,1), (float)luaL_checknumber(L,2), (float)luaL_checknumber(L,3), (float)luaL_checknumber(L,4)); LUA_GL_ERROR() }
 int lua_glColorMask(lua_State* L)				{  glColorMask(		(char)luaL_checkunsigned(L,1), (char)luaL_checkunsigned(L,2), (char)luaL_checkunsigned(L,3), (char)luaL_checkunsigned(L,4)); LUA_GL_ERROR() }


 
 int lua_glBlendFuncSeparate(lua_State* L)		{  glBlendFuncSeparate(		luaL_checkunsigned(L,1), luaL_checkunsigned(L,2), luaL_checkunsigned(L,3), luaL_checkunsigned(L,4)); LUA_GL_ERROR() }

 int lua_glCullFace(lua_State* L) { int p=1; glCullFace(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }


 int lua_glEnable(lua_State* L) { int p=1; glEnable(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glEnableVertexAttribArray(lua_State* L) { int p=1; glEnableVertexAttribArray(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glFinish(lua_State* L) { int p=1; glFinish(); LUA_GL_ERROR() }
 int lua_glFlush(lua_State* L) { int p=1; glFlush(); LUA_GL_ERROR() }

 

 int lua_glBufferData(lua_State* L)				{ int p=1; glBufferData(luaL_checkunsigned(L,1), luaL_checkunsigned(L,2), const GLvoid* data, luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glBufferSubData(lua_State* L)			{ int p=1; glBufferSubData(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++), const GLvoid* data); LUA_GL_ERROR() }

 
 int lua_glCompressedTexImage2D(lua_State* L) { int p=1; glCompressedTexImage2D(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), const GLvoid* data); LUA_GL_ERROR() }
 int lua_glCompressedTexSubImage2D(lua_State* L) { int p=1; glCompressedTexSubImage2D(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), const GLvoid* data); LUA_GL_ERROR() }
 int lua_glCopyTexImage2D(lua_State* L) { int p=1; glCopyTexImage2D(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
 int lua_glCopyTexSubImage2D(lua_State* L) { int p=1; glCopyTexSubImage2D(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }



 int lua_glFramebufferRenderbuffer(lua_State* L) { glFramebufferRenderbuffer (luaL_checkunsigned(L,1), luaL_checkunsigned(L,2), luaL_checkunsigned(L,3), luaL_checkunsigned(L,4)); LUA_GL_ERROR() }
 int lua_glFramebufferTexture2D(lua_State* L) { int p=1; glFramebufferTexture2D(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
 int lua_glFrontFace(lua_State* L) { int p=1; glFrontFace(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 
 int lua_glDepthFunc(lua_State* L) { int p=1; glDepthFunc(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glDepthMask(lua_State* L) { int p=1; glDepthMask((char)luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glDepthRangef(lua_State* L) { int p=1; glDepthRangef((float)luaL_checknumber(L,p++), (float)luaL_checknumber(L,p++)); LUA_GL_ERROR() }
 
 int lua_glDisable(lua_State* L) { int p=1; glDisable(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glDisableVertexAttribArray(lua_State* L) { int p=1; glDisableVertexAttribArray(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glDrawArrays(lua_State* L) { int p=1; glDrawArrays(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
 int lua_glLineWidth(lua_State* L) { int p=1; glLineWidth((float)luaL_checknumber(L,1)); LUA_GL_ERROR() }
 
 int lua_glPixelStorei(lua_State* L) { int p=1; glPixelStorei(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
 int lua_glGetString(lua_State* L) { lua_pushstring(L, glGetString(luaL_checkunsigned(L,1))); LUA_GL_EXTRA_RTN() }
 
 int lua_glStencilFuncSeparate(lua_State* L) { int p=1; glStencilFuncSeparate(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glStencilMask(lua_State* L) { int p=1; glStencilMask(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glStencilMaskSeparate(lua_State* L) { int p=1; glStencilMaskSeparate(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glStencilOp(lua_State* L) { int p=1; glStencilOp(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glStencilOpSeparate(lua_State* L) { int p=1; glStencilOpSeparate(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glTexImage2D(lua_State* L) { int p=1; glTexImage2D(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), const GLvoid* pixels); LUA_GL_ERROR() }
 int lua_glTexSubImage2D(lua_State* L) { int p=1; glTexSubImage2D(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), const GLvoid* pixels); LUA_GL_ERROR() }
 
 int lua_glDeleteBuffers(lua_State* L) { int p=1; glDeleteBuffers(luaL_checkinteger(L,p++), const GLuint* buffers); LUA_GL_ERROR() }
 int lua_glDeleteFramebuffers(lua_State* L) { int p=1; glDeleteFramebuffers(luaL_checkinteger(L,p++), const GLuint* framebuffers); LUA_GL_ERROR() }

 int lua_glDeleteRenderbuffers(lua_State* L) { int p=1; glDeleteRenderbuffers(luaL_checkinteger(L,p++), const GLuint* renderbuffers); LUA_GL_ERROR() }

 int lua_glDeleteTextures(lua_State* L) { int p=1; glDeleteTextures(luaL_checkinteger(L,p++), const GLuint* textures); LUA_GL_ERROR() }

 int lua_glDrawElements(lua_State* L) { int p=1; glDrawElements(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++), const GLvoid* indices); LUA_GL_ERROR() }
 int lua_glGenBuffers(lua_State* L) { int p=1; glGenBuffers(luaL_checkinteger(L,p++), GLuint* buffers); LUA_GL_ERROR() }
 int lua_glGenerateMipmap(lua_State* L) { int p=1; glGenerateMipmap(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glGenFramebuffers(lua_State* L) { int p=1; glGenFramebuffers(luaL_checkinteger(L,p++), GLuint* framebuffers); LUA_GL_ERROR() }
 int lua_glGenRenderbuffers(lua_State* L) { int p=1; glGenRenderbuffers(luaL_checkinteger(L,p++), GLuint* renderbuffers); LUA_GL_ERROR() }
 int lua_glGenTextures(lua_State* L) { int p=1; glGenTextures(luaL_checkinteger(L,p++), GLuint* textures); LUA_GL_ERROR() }
 int lua_glGetActiveAttrib(lua_State* L) { int p=1; glGetActiveAttrib(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), GLsizei* length, GLint* size, GLenum* type, GLchar* name); LUA_GL_ERROR() }
 int lua_glGetActiveUniform(lua_State* L) { int p=1; glGetActiveUniform(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), GLsizei* length, GLint* size, GLenum* type, GLchar* name); LUA_GL_ERROR() }

 int lua_glGetBooleanv(lua_State* L) { int p=1; glGetBooleanv(luaL_checkunsigned(L,p++), GLboolean* params); LUA_GL_ERROR() }
 int lua_glGetBufferParameteriv(lua_State* L) { int p=1; glGetBufferParameteriv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLint* params); LUA_GL_ERROR() }
 luaL_checkunsigned(L,p++) (void);
 int lua_glGetFloatv(lua_State* L) { int p=1; glGetFloatv(luaL_checkunsigned(L,p++), GLfloat* params); LUA_GL_ERROR() }
 int lua_glGetFramebufferAttachmentParameteriv(lua_State* L) { int p=1; glGetFramebufferAttachmentParameteriv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLint* params); LUA_GL_ERROR() }
 int lua_glGetIntegerv(lua_State* L) { int p=1; glGetIntegerv(luaL_checkunsigned(L,p++), GLint* params); LUA_GL_ERROR() }
 int lua_glGetRenderbufferParameteriv(lua_State* L) { int p=1; glGetRenderbufferParameteriv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLint* params); LUA_GL_ERROR() }
 
 int lua_glGetTexParameterfv(lua_State* L) { int p=1; glGetTexParameterfv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLfloat* params); LUA_GL_ERROR() }
 int lua_glGetTexParameteriv(lua_State* L) { int p=1; glGetTexParameteriv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLint* params); LUA_GL_ERROR() }
 int lua_glGetUniformfv(lua_State* L) { int p=1; glGetUniformfv(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), GLfloat* params); LUA_GL_ERROR() }
 int lua_glGetUniformiv(lua_State* L) { int p=1; glGetUniformiv(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), GLint* params); LUA_GL_ERROR() }

 int lua_glGetVertexAttribfv(lua_State* L) { int p=1; glGetVertexAttribfv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLfloat* params); LUA_GL_ERROR() }
 int lua_glGetVertexAttribiv(lua_State* L) { int p=1; glGetVertexAttribiv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLint* params); LUA_GL_ERROR() }
 int lua_glGetVertexAttribPointerv(lua_State* L) { int p=1; glGetVertexAttribPointerv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLvoid** pointer); LUA_GL_ERROR() }

 
 int lua_glPolygonOffset(lua_State* L) { int p=1; glPolygonOffset((float)luaL_checknumber(L,1), GLfloat units); LUA_GL_ERROR() }
 int lua_glReadPixels(lua_State* L) { int p=1; glReadPixels(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLvoid* pixels); LUA_GL_ERROR() }
 int lua_glReleaseShaderCompiler(lua_State* L) { int p=1; glReleaseShaderCompiler(void); LUA_GL_ERROR() }
 int lua_glRenderbufferStorage(lua_State* L) { int p=1; glRenderbufferStorage(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
 int lua_glSampleCoverage(lua_State* L) { int p=1; glSampleCoverage((float)luaL_checknumber(L,p++), (char)luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glScissor(lua_State* L) { int p=1; glScissor(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
  int lua_glStencilFunc(lua_State* L) { int p=1; glStencilFunc(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glStencilFuncSeparate(lua_State* L) { int p=1; glStencilFuncSeparate(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glStencilMask(lua_State* L) { int p=1; glStencilMask(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glStencilMaskSeparate(lua_State* L) { int p=1; glStencilMaskSeparate(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glStencilOp(lua_State* L) { int p=1; glStencilOp(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glStencilOpSeparate(lua_State* L) { int p=1; glStencilOpSeparate(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glTexImage2D(lua_State* L) { int p=1; glTexImage2D(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), const GLvoid* pixels); LUA_GL_ERROR() }
 int lua_glTexParameterf(lua_State* L) { int p=1; glTexParameterf(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), GLfloat param); LUA_GL_ERROR() }
 int lua_glTexParameterfv(lua_State* L) { int p=1; glTexParameterfv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), const GLfloat* params); LUA_GL_ERROR() }
 int lua_glTexParameteri(lua_State* L) { int p=1; glTexParameteri(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
 int lua_glTexParameteriv(lua_State* L) { int p=1; glTexParameteriv(luaL_checkunsigned(L,p++), luaL_checkunsigned(L,p++), const GLint* params); LUA_GL_ERROR() }

 // combined uniform.  depends on
 int lua_glUniform1i(lua_State *L) {


 }
 int lua_glUniform1f(lua_State* L) { int p=1; glUniform1f(luaL_checkinteger(L,p++), GLfloat x); LUA_GL_ERROR() }
 int lua_glUniform2f(lua_State* L) { int p=1; glUniform2f(luaL_checkinteger(L,p++), GLfloat x, GLfloat y); LUA_GL_ERROR() }
 int lua_glUniform3f(lua_State* L) { int p=1; glUniform3f(luaL_checkinteger(L,p++), GLfloat x, GLfloat y, GLfloat z); LUA_GL_ERROR() }
 int lua_glUniform4f(lua_State* L) { int p=1; glUniform4f(luaL_checkinteger(L,p++), GLfloat x, GLfloat y, GLfloat z, GLfloat w); LUA_GL_ERROR() }
 int lua_glUniform4fv(lua_State* L) { int p=1; glUniform4fv(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), const GLfloat* v); LUA_GL_ERROR() }

 int lua_glUniform3fv(lua_State* L) { int p=1; glUniform3fv(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), const GLfloat* v); LUA_GL_ERROR() }
 int lua_glUniform2fv(lua_State* L) { int p=1; glUniform2fv(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), const GLfloat* v); LUA_GL_ERROR() }
 int lua_glUniform1fv(lua_State* L) { int p=1; glUniform1fv(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), const GLfloat* v); LUA_GL_ERROR() }
 int lua_glUniform1i(lua_State* L) { int p=1; glUniform1i(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
 int lua_glUniform1iv(lua_State* L) { int p=1; glUniform1iv(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), const GLint* v); LUA_GL_ERROR() }
 
 
 int lua_glUniform2i(lua_State* L) { int p=1; glUniform2i(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
 int lua_glUniform2iv(lua_State* L) { int p=1; glUniform2iv(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), const GLint* v); LUA_GL_ERROR() }
 

 int lua_glUniform3i(lua_State* L) { int p=1; glUniform3i(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
 int lua_glUniform3iv(lua_State* L) { int p=1; glUniform3iv(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), const GLint* v); LUA_GL_ERROR() }
  int lua_glUniform4i(lua_State* L) { int p=1; glUniform4i(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
 int lua_glUniform4iv(lua_State* L) { int p=1; glUniform4iv(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), const GLint* v); LUA_GL_ERROR() }

 int lua_glUniformMatrix2fv(lua_State* L) { int p=1; glUniformMatrix2fv(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), (char)luaL_checkunsigned(L,p++), const GLfloat* value); LUA_GL_ERROR() }
 int lua_glUniformMatrix3fv(lua_State* L) { int p=1; glUniformMatrix3fv(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), (char)luaL_checkunsigned(L,p++), const GLfloat* value); LUA_GL_ERROR() }
 int lua_glUniformMatrix4fv(lua_State* L) { int p=1; glUniformMatrix4fv(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), (char)luaL_checkunsigned(L,p++), const GLfloat* value); LUA_GL_ERROR() }
 int lua_glUseProgram(lua_State* L) { int p=1; glUseProgram(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glValidateProgram(lua_State* L) { int p=1; glValidateProgram(luaL_checkunsigned(L,p++)); LUA_GL_ERROR() }
 int lua_glVertexAttrib1f(lua_State* L) { int p=1; glVertexAttrib1f(luaL_checkunsigned(L,p++), GLfloat x); LUA_GL_ERROR() }
 int lua_glVertexAttrib1fv(lua_State* L) { int p=1; glVertexAttrib1fv(luaL_checkunsigned(L,p++), const GLfloat* values); LUA_GL_ERROR() }
 int lua_glVertexAttrib2f(lua_State* L) { int p=1; glVertexAttrib2f(luaL_checkunsigned(L,p++), GLfloat x, GLfloat y); LUA_GL_ERROR() }
 int lua_glVertexAttrib2fv(lua_State* L) { int p=1; glVertexAttrib2fv(luaL_checkunsigned(L,p++), const GLfloat* values); LUA_GL_ERROR() }
 int lua_glVertexAttrib3f(lua_State* L) { int p=1; glVertexAttrib3f(luaL_checkunsigned(L,p++), GLfloat x, GLfloat y, GLfloat z); LUA_GL_ERROR() }
 int lua_glVertexAttrib3fv(lua_State* L) { int p=1; glVertexAttrib3fv(luaL_checkunsigned(L,p++), const GLfloat* values); LUA_GL_ERROR() }
 int lua_glVertexAttrib4f(lua_State* L) { int p=1; glVertexAttrib4f(luaL_checkunsigned(L,p++), GLfloat x, GLfloat y, GLfloat z, GLfloat w); LUA_GL_ERROR() }
 int lua_glVertexAttrib4fv(lua_State* L) { int p=1; glVertexAttrib4fv(luaL_checkunsigned(L,p++), const GLfloat* values); LUA_GL_ERROR() }
 int lua_glVertexAttribPointer(lua_State* L) { int p=1; glVertexAttribPointer(luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), luaL_checkunsigned(L,p++), (char)luaL_checkunsigned(L,p++), luaL_checkinteger(L,p++), const GLvoid* ptr); LUA_GL_ERROR() }
 int lua_glViewport(lua_State* L) { int p=1; glViewport(luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++), luaL_checkinteger(L,p++)); LUA_GL_ERROR() }
