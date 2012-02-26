// Lua52opengles.cpp : Defines the entry point for the console application.
//


#include "lua_print.h"
#include "Texture2D.h"
#include <lua.hpp>

char* testarguments[] = { "-v" , NULL };

int _tmain(int argc, _TCHAR* argv[])
{
#if TEST
	int status, result;
	lua_State *L = luaL_newstate();  // create state 
	if (L == NULL) {
		//l_message(argv[0], "cannot create state: not enough memory");
		return EXIT_FAILURE;
	}
    // load the libs
    luaL_openlibs(L);
    luaL_dofile(L,"example.lua");
    printf("\nDone!\n");
    lua_close(L);

    return 0;
#else
	return lua_main(1,testarguments);
#endif
}

