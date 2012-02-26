#include "stdafx.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define _CRT_SECURE_NO_WARRINGS
#define MAX_DEBUG_BUFF 1023
int gl_debug(const char * msg,...) {
	char buff[MAX_DEBUG_BUFF+1];
	va_list args;
	size_t len=0;
	GLenum e;

	e = glGetError();
	if(!e) { return 0; } // no error 
	va_start(args, msg); 

	const char*  error = (const char*)glGetString(e); 
	len=sprintf_s(buff,MAX_DEBUG_BUFF,"GLERROR: %s\n",error);
	va_start(args,msg);
	vsprintf(buff+len-1, msg, args );  
	va_end(args);
	return 1;
}