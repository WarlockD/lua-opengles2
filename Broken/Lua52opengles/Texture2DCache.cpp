#include "Texture2DCache.h"

#include <lua.hpp>
#include <string>
#include <map>
#include "ImageLoader.h"
#include <assert.h>
#include <iostream>

static std::map<std::string,Texture2D> _textures;
typedef std::map<std::string,Texture2D>::iterator textItr;
bool trickskip = true;
Texture2DCache* g_Texture2DCache;


inline static bool _findtexture(const std::string& filename, textItr& it)
{
	it = _textures.find(filename);
	if(it != _textures.end())
		return true;
	else
		return false;
}
const Texture2DCache* Texture2DCache::SharedCache()
{
	if(!g_Texture2DCache)
		g_Texture2DCache = new Texture2DCache();

	return g_Texture2DCache;
}
Texture2DCache::Texture2DCache() { }
Texture2DCache::~Texture2DCache() { 
	UnloadAllTextures();
}
//const Texture2DCache* Texture2DCache::Cache()
//{
//	if(!g_Texture2DCache) g_Texture2DCache = new Texture2DCache();
//	return g_Texture2DCache;	
//}

bool Texture2DCache::UnloadAllTextures()
{
	textItr itr;
	for(itr = _textures.begin(); itr!=_textures.end();itr++) 
		itr->second.UnloadImage();
	return true;
}
bool Texture2DCache::LoadAllTextures()
{
	bool haserror = false;
	textItr itr;
	for(itr = _textures.begin(); itr!=_textures.end();itr++) if(!itr->second.LoadImage()) haserror = true;
	return haserror;
}
GLuint Texture2DCache::LoadTexture(const char* filename)
{
	textItr it;
	Texture2D& load = _textures[std::string(filename)];
	if(load != filename) load.setFilename(filename); // new texture
	if(load.glTexture()) return load.glTexture();

	if(load.LoadTexture())
	{
		// print out error if we got one
		std::cout << load.error_str() << ": Error loading in GL" << std::endl;
		assert(image.error());
		return 0;
	}
	return load.glTexture();
}

bool Texture2DCache::deleteTexture(const char* filename)
{
	return _textures.erase(std::string(filename)) > 0 ? true : false;
}

GLuint Texture2DCache::findTexture(const char* filename) 
{
	textItr it;
	if(_findtexture(filename,it)) 
		return it->second.glTexture();
	else
		return 0;
}

// lua part
