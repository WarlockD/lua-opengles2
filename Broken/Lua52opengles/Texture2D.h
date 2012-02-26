#pragma once

#include <lua.hpp>
#include "gl_debug.h"
#include <GLES2/gl2.h>

namespace Texture {
	struct t_imageinfo {
		int width;
		int height;
		int bbp;
		GLuint tex;
	};
	void init();
	int find(const char* filename, t_imageinfo& info);
	void unload();
	void reload();
	void InitLua(lua_State* L);
};
