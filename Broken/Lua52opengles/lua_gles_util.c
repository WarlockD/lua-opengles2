
#include <stddef.h>
#include "lua_gles.h"





static float* getindex_float_array(lua_State* L) {
	size_t n;  int e;  t_array *a;

	a =  (t_array*)luaL_checkudata(L,1,LUA_FLOAT_ARRAY_METATABLE);
	if(!a) { luaL_argerror(L,1,"wrong metatable?");  return NULL; }
	
	n = lua_tounsignedx(L,2,&e);
	if(!e) {  luaL_argerror(L,2,"Invalid type"); return NULL;}
	if(n+1 > a->s) { luaL_argerror(L,2,"Out of bounds");  return NULL; }
	return ARRAY_CAST(a,float) + n;
}

static int set_float_array(lua_State* L) {
	float* a;  int t;
	a = getindex_float_array(L);// if(a==NULL) return 0;
	t = lua_type(L,3);

	switch(t) {
		case LUA_TNIL: *a = 0.0f; break;		
		case LUA_TBOOLEAN: *a = lua_toboolean(L,3) ? 1.0f : 0.0f;  break;
		case LUA_TNUMBER: *a = (float)lua_tonumber(L,3); break;	
		default:
			lua_pushstring(L,"Invalid float value");
			lua_error(L);
			return 1;
	}
	return 0;
}

static int get_float_array(lua_State* L)	{ 
	float* a = NULL; 
	a = getindex_float_array(L); if(!a) return 0;
	lua_pushnumber(L,*a); 
	return 1; 
}

static int size_float_array(lua_State* L)		{ 
	t_array *d = NULL;
	d = (t_array*)luaL_checkudata(L,1, LUA_FLOAT_ARRAY_METATABLE);
	if(!d)  return luaL_argerror(L,2,"wrong metatable?");  
	lua_pushunsigned(L,d->s); 
	return 1; 
}

static int tostring_float_array(lua_State* L)	{ 
	t_array * d = NULL;
	d = (t_array*)luaL_checkudata(L,1, LUA_FLOAT_ARRAY_METATABLE);
	if(!d)  return luaL_argerror(L,2,"wrong metatable?");  
	lua_pushfstring(L,"FloatBuffer(%d)",d->s); 
	return 1; 
}

static int gc_float_array(lua_State* L)		{ return 0; } // dosn't matter but good to havereturn 0;


static const struct luaL_Reg float_array_lib_m[] = {
	{"__newindex",set_float_array},
	{"__index", get_float_array},
	{"__len",size_float_array},
	{"__tostring",tostring_float_array},
	{"__gc", gc_float_array},
	{NULL,NULL}
};
	
static int* getindex_int_array(lua_State* L) {
	size_t n;  int e;  t_array * a;

	a =  (t_array*)luaL_checkudata(L,1,LUA_INT_ARRAY_METATABLE);
	if(!a) { luaL_argerror(L,1,"wrong metatable?");  return NULL; }
	
	n = lua_tounsignedx(L,2,&e);
	if(!e) {  luaL_argerror(L,2,"Invalid type"); return NULL;}
	if(n+1 > a->s) { luaL_argerror(L,2,"Out of bounds");  return NULL; }
	return ARRAY_CAST(a,int) + n;
}

static int set_int_array(lua_State* L) {
	int* a;  int t;
	a = getindex_int_array(L);// if(a==NULL) return 0;
	t = lua_type(L,3);

	switch(t) {
		case LUA_TNIL: *a = 0; break;		
		case LUA_TBOOLEAN: *a = lua_toboolean(L,3) ? 1 : 0;  break;
		case LUA_TNUMBER: *a = lua_tointeger(L,3); break;	
		default:
			lua_pushstring(L,"Invalid int value");
			lua_error(L);
			return 1;
	}
	return 0;
}

static int size_int_array(lua_State* L)		{ 
	t_array *d = NULL;
	d = (t_array*)luaL_checkudata(L,1, LUA_INT_ARRAY_METATABLE);
	if(!d)  return luaL_argerror(L,2,"wrong metatable?");  
	lua_pushunsigned(L,d->s); 
	return 1; 
}
static int tostring_int_array(lua_State* L)	{ 
	t_array * d = NULL;
	d = (t_array*)luaL_checkudata(L,1, LUA_INT_ARRAY_METATABLE);
	if(!d)  return luaL_argerror(L,2,"wrong metatable?");  
	lua_pushfstring(L,"intBuffer(%d)",d->s); 
	return 1; 
}
static int get_int_array(lua_State* L)	{ 
	int* a = NULL; 
	a = getindex_int_array(L); if(!a) return 0;
	lua_pushnumber(L,*a); 
	return 1; 
}
static int gc_int_array(lua_State* L)		{ return 0; } // dosn't matter but good to havereturn 0;

static const struct luaL_Reg int_array_lib_m[] = {
	{"__newindex",set_int_array},
	{"__index", get_int_array},
	{"__len",size_int_array},
	{"__tostring",tostring_int_array},
	{"__gc", gc_int_array},
	{NULL,NULL}
};
#define NEW_ARRAY_USERDATA(type,size) \
	if( size >=1) { lua_pushstring(L,"Invalid inital size"); lua_error(L); return 1; } \
	a = (t_array*)lua_newuserdata(L,sizeof(t_array) + sizeof( type ) * size ); \
	if(!a) { lua_pushstring(L,"Alloc error"); lua_error(L); return 1; } else a->s = size ;

static int new_float_array(lua_State* L) {
	int i,n,s,l;
	t_array* a=NULL;
	l = lua_gettop(L);

	if(l==1 && lua_type(L,1) == LUA_TNUMBER) { // new(size)
		n = lua_tointeger(L,1);
		NEW_ARRAY_USERDATA(float,n)

		for(i=0;i < n; i++) ARRAY_F(a,i) =0.0f;
		luaL_setmetatable(L,LUA_INT_ARRAY_METATABLE);
		return 1;
	}
	if(l==1 && lua_type(L,1) == LUA_TTABLE) { // new(table)
		n = lua_rawlen(L,1);
		NEW_ARRAY_USERDATA(float,n)

		for(i=0;i<n;i++) {
			lua_rawgeti(L,1,i+1);
			ARRAY_F(a,i) = (float)lua_tonumber(L,-1);
			lua_pop(L,-1);
		}
		luaL_setmetatable(L,LUA_FLOAT_ARRAY_METATABLE);
		return 1;
	}
	if(l==2 && lua_type(L,1) == LUA_TTABLE && lua_type(L,2) == LUA_TNUMBER) { // new(table,size)
		n = lua_rawlen(L,1);
		s = lua_tointeger(L,2);
		if(s>n) { lua_pushfstring(L,"Table size to small.  Len: %d, parm: %d",n,s); lua_error(L); return 1; }
		NEW_ARRAY_USERDATA(float,n)
		


		for(i=0;i<n;i++) {
			lua_rawgeti(L,1,i+1);
			ARRAY_F(a,i) = (float)lua_tonumber(L,-1);
			lua_pop(L,-1);
		}
		luaL_setmetatable(L,LUA_FLOAT_ARRAY_METATABLE);
		return 1;
	}

	lua_pushstring(L,"Invalid parms value"); 
	lua_error(L); 
	return 1; 
}
static int new_int_array(lua_State* L) {
	int i,n,s,l;
	t_array* a=NULL;
	l = lua_gettop(L);

	if(l==1 && lua_type(L,1) == LUA_TNUMBER) { // new(size)
		n = lua_tointeger(L,1);
		NEW_ARRAY_USERDATA(int,n)

		for(i=0;i < n; i++) ARRAY_F(a,i) =0.0f;
		luaL_setmetatable(L,LUA_INT_ARRAY_METATABLE);
		return 1;
	}
	if(l==1 && lua_type(L,1) == LUA_TTABLE) { // new(table)
		n = lua_rawlen(L,1);
		NEW_ARRAY_USERDATA(int,n)

		for(i=0;i<n;i++) {
			lua_rawgeti(L,1,i+1);
			ARRAY_I(a,i) = lua_tointeger(L,-1);
			lua_pop(L,-1);
		}
		luaL_setmetatable(L,LUA_INT_ARRAY_METATABLE);
		return 1;
	}
	if(l==2 && lua_type(L,1) == LUA_TTABLE && lua_type(L,2) == LUA_TNUMBER) { // new(table,size)
		n = lua_rawlen(L,1);
		s = lua_tointeger(L,2);
		if(s>n) { lua_pushfstring(L,"Table size to small.  Len: %d, parm: %d",n,s); lua_error(L); return 1; }
		NEW_ARRAY_USERDATA(int,n)
		


		for(i=0;i<n;i++) {
			lua_rawgeti(L,1,i+1);
			ARRAY_I(a,i) = lua_tointeger(L,-1);
			lua_pop(L,-1);
		}
		luaL_setmetatable(L,LUA_INT_ARRAY_METATABLE);
		return 1;
	}

	lua_pushstring(L,"Invalid parms value"); 
	lua_error(L); 
	return 1; 
}
static const struct luaL_Reg array_lib_f[] = {
	{"newfloat",new_float_array},
	{"newInt",new_int_array},
	{NULL,NULL}
};
int luaopen_float_array(lua_State *L) {
	luaL_newmetatable(L,LUA_FLOAT_ARRAY_METATABLE);
	luaL_setfuncs(L,float_array_lib_m,0);
	luaL_newmetatable(L,LUA_INT_ARRAY_METATABLE);
	luaL_setfuncs(L,int_array_lib_m,0);

	luaL_newlibtable(L,"glUtil");
	luaL_setfuncs(L,array_lib_f,0);

	return 1;
}