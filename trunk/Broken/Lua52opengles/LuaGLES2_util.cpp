#include <string.h>
#include <lua.hpp>
#include "LuaGLES2_util.h"






int luagl_str2mask(const char *str)
{
  int i, j;
  int mask = 0;
  int size = (int)strlen(str);
  for(i = 0, j = 0; j < size; i++)
  {
    if(str[i] == '1')
    {
      mask |= (1 << (size-1-j));
      j++;
    }
    else if(str[i] == '0')
      j++;

  }
  return mask;
}

const char *luagl_mask2str(int mask)
{
  unsigned int i;
  static char str[17];
  for(i = 0; i < 16; i++)
  {
    if(mask & (1 << (15 - i)))
      str[i] = '1';
    else
      str[i] = '0';
  }
  str[i] = 0;
  return str;
}

static unsigned int luagl_find_enum(const lualgesConst* gl_const, const char *str, int n)
{
  int i = 0;

  while(gl_const[i].str != 0)
  {
    if(strncmp(str, gl_const[i].str, n) == 0 && gl_const[i].str[n] == 0)
      return gl_const[i].value;
    i++;
  }
  return LUAGL_ENUM_ERROR;
}

unsigned int luagl_get_enum(lua_State *L, int index, const lualgesConst* gl_const)
{
  if (lua_isnumber(L, index))
  {
    return (unsigned int)luaL_checkinteger(L, index);
  }
  else
  {
    unsigned int i;
    const char *str = luaL_checkstring(L, index);
    unsigned int len = (unsigned int)strlen(str);
    unsigned int temp = 0, ret = 0, found = 0;

    for(i = 0; i < len; i++)
    {
      if(str[i] == ',')
      {
        temp = luagl_find_enum(gl_const, str, i);
        if (temp != LUAGL_ENUM_ERROR)
        {
          ret |= temp;
          found = 1;
        }

        str += i+1;
        len -= i+1;
        i = 0;
      }
    }
    temp = luagl_find_enum(gl_const, str, len);

    if (temp == LUAGL_ENUM_ERROR)
    {
      if (!found)
      {
        luaL_argerror(L, index, "unknown or invalid enumeration");
        return LUAGL_ENUM_ERROR;
      }

      return ret;
    }

    return ret | temp;
  }
}


