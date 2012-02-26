#ifndef __TEXTURE2DCACHE_H__
#define __TEXTURE2DCACHE_H__


#include <lua.hpp>
#include "Texture2D.h"
#include <GLES2/gl2.h>

class Texture2DCache
{
private:
	Texture2DCache();
public:
	static void InitLua(lua_State *L);
	static const Texture2DCache* SharedCache();
	bool UnloadAllTextures();
	bool LoadAllTextures();
	GLuint LoadTexture(const char* filename);
	bool deleteTexture(const char* filename);
	GLuint findTexture(const char* filename);
	~Texture2DCache();
};

extern Texture2DCache * g_Texture2DCache ;


#endif