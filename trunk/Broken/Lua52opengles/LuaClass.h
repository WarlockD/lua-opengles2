#ifndef __LUACLASS_H_
#define __LUACLASS_H_

#include <lua.hpp>

class LuaClass
{
public:
	LuaClass();
	~LuaClass();
	virtual int len() const = 0;
protected:
	void* mValue;



};



#endif