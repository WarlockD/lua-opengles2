#ifndef _ESUTIL_LUA_H_
#define _ESUTIL_LUA_H_



#ifdef __cplusplus
extern "C" {
#endif 
	#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
void esUtil_luaReg(lua_State *L);

#ifdef __cplusplus
}
#endif


#endif