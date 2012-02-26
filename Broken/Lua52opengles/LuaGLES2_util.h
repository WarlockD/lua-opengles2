#ifndef __LUAGLES2_UTIL_H__
#define __LUAGLES2_UTIL_H__

#include "stdafx.h"

struct lualgesConst  
{
	GLenum value;
	const char *str;
} ;
template<class T> class LuaArray
{
private:
	void* pushFunc;
	void* conversionFunc;
public:
	T* val;
	int count;
	
	LuaArray(): val(NULL),count(0),conversionFunc(&lua_tonumberx), pushFunc(&lua_pushnumber) {}
	~LuaArray() { if(val) delete val;} 
	LuaArray(int size){  LuaArray(); val = new float[size]; count = size; }
	LuaArray(lua_State *L, int index)
	{            
		LuaArray();
		luaL_checktype(L, index, LUA_TTABLE);      
		lua_gettable(L,index);
		lua_len(L,index); count = lua_tointeger(L,-1); lua_remove(L, -1);  
		val = new T[count]; 
                                                      
		for(int i = 0; i < count; i++) {                                 
			lua_rawgeti(L, index, i+1);                                 
			val[i] = (T)(conversionFunc)(L, -1,NULL);               
			lua_remove(L, -1);                                          
		} 
		lua_remove(L, -1);    
	}
	void Push_Table(lua_State *L) const
	{                                           
		lua_createtable(L, count, 0);                        
		for(int i = 0; i < count; i++)                           
		{                                                   
			lua_pushinteger(L, i+1);                          
			(pushFunc)(L, (T)val[i]);                    
			lua_settable(L, -3);                              
		}       
	}
};

LuaArray<unsigned int>::LuaArray() : val(NULL),count(0),conversionFunc(&lua_tounsignedx), pushFunc(&lua_pushunsigned) {}
LuaArray<int>::LuaArray() : val(NULL),count(0),conversionFunc(&lua_tointegerx), pushFunc(&lua_pushinteger) {}
LuaArray<unsigned char>::LuaArray() : val(NULL),count(0),conversionFunc(&lua_tounsignedx), pushFunc(&lua_pushunsigned) {}
LuaArray<char>::LuaArray() : val(NULL),count(0),conversionFunc(&lua_tointegerx), pushFunc(&lua_pushinteger) {}
LuaArray<bool>::LuaArray() : val(NULL),count(0),conversionFunc(&lua_toboolean), pushFunc(&lua_pushboolean) {}


void luagl_initconst(lua_State *L, const lualgesConst *gl_const);
unsigned int luagl_get_enum(lua_State *L, int index, const lualgesConst* gl_const);
unsigned int luagl_get_gl_enum(lua_State *L, int index);
int luagl_checkboolean (lua_State *L, int narg);
void* luagl_checkuserdata (lua_State *L, int narg);

#define LUAGL_ENUM_ERROR (unsigned int)-2

/* returns an parray with given type and size */
#define LUAGL_NEW_ARRAY(_type, _size) ( (_type *)malloc((_size) * sizeof(_type)) )

/* frees the space for the given parray, must be called together with LUAGL_NEW_ARRAY */
#define LUAGL_DELETE_ARRAY(_parray) { if(_parray) {free(_parray);} }


int luagl_str2mask(const char *str);
const char *luagl_mask2str(int mask);

#endif
