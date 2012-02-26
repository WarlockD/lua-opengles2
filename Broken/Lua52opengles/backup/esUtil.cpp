//
// Book:      OpenGL(R) ES 2.0 Programming Guide
// Authors:   Aaftab Munshi, Dan Ginsburg, Dave Shreiner
// ISBN-10:   0321502795
// ISBN-13:   9780321502797
// Publisher: Addison-Wesley Professional
// URLs:      http://safari.informit.com/9780321563835
//            http://www.opengles-book.com
//

// ESUtil.c
//
//    A utility library for OpenGL ES.  This library provides a
//    basic common framework for the example applications in the
//    OpenGL ES 2.0 Programming Guide.
//

///
//  Includes
//
#include <stdio.h>
#include <stdlib.h>
#include <GLES2/gl2.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include "esUtil.h"
#include "esUtil_win.h"


///
//  Extensions
//

//PFNEGLPOSTSUBBUFFERNVPROC eglPostSubBufferNV;

PFNGLDELETEFENCESNVPROC glDeleteFencesNV;
PFNGLGENFENCESNVPROC glGenFencesNV;
PFNGLGETFENCEIVNVPROC glGetFenceivNV;
PFNGLISFENCENVPROC glIsFenceNV;
PFNGLFINISHFENCENVPROC glFinishFenceNV;
PFNGLSETFENCENVPROC glSetFenceNV;
PFNGLTESTFENCENVPROC glTestFenceNV;

///
// CreateEGLContext()
//
//    Creates an EGL rendering context and all associated elements
//
EGLBoolean CreateEGLContext ( EGLNativeWindowType hWnd, EGLDisplay* eglDisplay,
                              EGLContext* eglContext, EGLSurface* eglSurface,
                              EGLint* configAttribList, EGLint* surfaceAttribList)
{
   EGLint numConfigs;
   EGLint majorVersion;
   EGLint minorVersion;
   EGLDisplay display;
   EGLContext context;
   EGLSurface surface;
   EGLConfig config;
   EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE, EGL_NONE };
   
   // Get Display
   display = eglGetDisplay(GetDC(hWnd));
   if ( display == EGL_NO_DISPLAY )
   {
      return EGL_FALSE;
   }

   // Initialize EGL
   if ( !eglInitialize(display, &majorVersion, &minorVersion) )
   {
      return EGL_FALSE;
   }

   // Bind to extensions
   //eglPostSubBufferNV = (PFNEGLPOSTSUBBUFFERNVPROC) eglGetProcAddress("eglPostSubBufferNV");

   glDeleteFencesNV = (PFNGLDELETEFENCESNVPROC) eglGetProcAddress("glDeleteFencesNV");
   glGenFencesNV = (PFNGLGENFENCESNVPROC) eglGetProcAddress("glGenFencesNV");
   glGetFenceivNV = (PFNGLGETFENCEIVNVPROC) eglGetProcAddress("glGetFenceivNV");
   glIsFenceNV = (PFNGLISFENCENVPROC) eglGetProcAddress("glIsFenceNV");
   glFinishFenceNV = (PFNGLFINISHFENCENVPROC) eglGetProcAddress("glFinishFenceNV");
   glSetFenceNV = (PFNGLSETFENCENVPROC) eglGetProcAddress("glSetFenceNV");
   glTestFenceNV = (PFNGLTESTFENCENVPROC) eglGetProcAddress("glTestFenceNV");

   // Get configs
   if ( !eglGetConfigs(display, NULL, 0, &numConfigs) )
   {
      return EGL_FALSE;
   }

   // Choose config
   if ( !eglChooseConfig(display, configAttribList, &config, 1, &numConfigs) )
   {
      return EGL_FALSE;
   }

   // Create a surface
   surface = eglCreateWindowSurface(display, config, (EGLNativeWindowType)hWnd, surfaceAttribList);
   if ( surface == EGL_NO_SURFACE )
   {
      return EGL_FALSE;
   }

   // Create a GL context
   context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs );
   if ( context == EGL_NO_CONTEXT )
   {
      return EGL_FALSE;
   }   
   
   // Make the context current
   if ( !eglMakeCurrent(display, surface, surface, context) )
   {
      return EGL_FALSE;
   }
   
   *eglDisplay = display;
   *eglSurface = surface;
   *eglContext = context;
   return EGL_TRUE;
} 

//////////////////////////////////////////////////////////////////
//
//  Public Functions
//
//

///
//  esInitContext()
//
//      Initialize ES utility context.  This must be called before calling any other
//      functions.
//
ESContext::ESContext(): _userData(NULL),_width(0),_height(0), 
	_hWnd(NULL),_eglDisplay(NULL),_eglContext(NULL),_eglSurface(NULL),
	_draws(),_updates(),_keys() {}

///
//  esCreateWindow()
//
//      title - name for title bar of window
//      width - width of window to create
//      height - height of window to create
//      flags  - bitwise or of window creation flags 
//          ES_WINDOW_ALPHA       - specifies that the framebuffer should have alpha
//          ES_WINDOW_DEPTH       - specifies that a depth buffer should be created
//          ES_WINDOW_STENCIL     - specifies that a stencil buffer should be created
//          ES_WINDOW_MULTISAMPLE - specifies that a multi-sample buffer should be created
//          ES_WINDOW_POST_SUB_BUFFER_SUPPORTED - specifies that EGL_POST_SUB_BUFFER_NV is supported.
//
bool ESContext::Create(  LPCTSTR title, GLint width, GLint height, GLuint flags )
{
   EGLint configAttribList[] =
   {
       EGL_RED_SIZE,       5,
       EGL_GREEN_SIZE,     6,
       EGL_BLUE_SIZE,      5,
       EGL_ALPHA_SIZE,     (flags & ES_WINDOW_ALPHA) ? 8 : EGL_DONT_CARE,
       EGL_DEPTH_SIZE,     (flags & ES_WINDOW_DEPTH) ? 8 : EGL_DONT_CARE,
       EGL_STENCIL_SIZE,   (flags & ES_WINDOW_STENCIL) ? 8 : EGL_DONT_CARE,
       EGL_SAMPLE_BUFFERS, (flags & ES_WINDOW_MULTISAMPLE) ? 1 : 0,
       EGL_NONE
   };
   EGLint surfaceAttribList[] =
   {
       //EGL_POST_SUB_BUFFER_SUPPORTED_NV, 
	   flags & (ES_WINDOW_POST_SUB_BUFFER_SUPPORTED) ? EGL_TRUE : EGL_FALSE,
       EGL_NONE, EGL_NONE
   };
   
   if ( _eglContext == NULL )
   {
      return GL_FALSE;
   }

   _width = width;
   _height = height;

   if ( !WinCreate (title) )
   {
      return GL_FALSE;
   }

  
   if ( !CreateEGLContext ( _hWnd,
                            &_eglDisplay,
                            &_eglContext,
                            &_eglSurface,
                            configAttribList,
                            surfaceAttribList ) )
   {
      return GL_FALSE;
   }
   

   return GL_TRUE;
}
std::list<DrawFunc> _draws;
	std::list<UpdateFunc> _updates;
	std::list<KeyFunc> _keys;
void ESContext::RegisterDrawFunc(const DrawFunc& f) { _draws.push_back(f); }
void ESContext::RegisterUpdateFunc(const UpdateFunc&  f) { _updates.push_back(f); }
void ESContext::RegisterKeyFunc (const KeyFunc&  f) { _keys.push_back(f); }

void ESContext::DrawAll() {
	std::list<DrawFunc>::iterator it;
	for(it=_draws.begin();it!=_draws.end();it++)
		it->Draw();
}
void ESContext::UpdateAll(float dt) {
	std::list<UpdateFunc>::iterator it;
	for(it=_updates.begin();it!=_updates.end();it++)
		it->Update(dt);
}
void ESContext::KeysAll(unsigned char c, int x, int y) {
	std::list<KeyFunc>::iterator it;
	for(it=_keys.begin();it!=_keys.end();it++)
		it->Key(c,x,y);
}

namespace GLES2 {
	void  LogMessage ( const char *formatStr, ... )
	{
		va_list params;
		char buf[BUFSIZ];

		va_start ( params, formatStr );
		vsprintf_s ( buf, sizeof(buf),  formatStr, params );
    
		printf ( "%s", buf );
    
		va_end ( params );
	}
};