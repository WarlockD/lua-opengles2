#ifndef _LUA_GLES_H_
#define _LUA_GLES_H_


#ifdef __cplusplus
extern "C" {
#endif
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
	typedef unsigned char t_byte;

#define LUA_FLOAT_ARRAY_METATABLE "__FloatBuffer"
#define LUA_INT_ARRAY_METATABLE "__intBuffer"
typedef struct { float x; float y; float z; float w; } t_fvec4;
typedef struct { float x; float y; float z;  } t_fvec3;
typedef struct { float x; float y;  } t_fvec2;
typedef struct  { size_t s; t_byte d[1]; } t_array;
#define ARRAY_CAST(arr,type) ((type*)arr->d)
#define ARRAY_F(arr, pos) *(ARRAY_CAST(arr,float) + pos)
#define ARRAY_I(arr, pos) *(ARRAY_CAST(arr,int) + pos)
#define ARRAY_SIZE(arr) arr->s

#define glbuff_type(n) (n->size & 0xF)


#ifdef __cplusplus
}
#endif

#endif