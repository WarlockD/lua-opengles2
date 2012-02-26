//
// Book:      OpenGL(R) ES 2.0 Programming Guide
// Authors:   Aaftab Munshi, Dan Ginsburg, Dave Shreiner
// ISBN-10:   0321502795
// ISBN-13:   9780321502797
// Publisher: Addison-Wesley Professional
// URLs:      http://safari.informit.com/9780321563835
//            http://www.opengles-book.com
//

//
/// \file ESUtil.h
/// \brief A utility library for OpenGL ES.  This library provides a
///        basic common framework for the example applications in the
///        OpenGL ES 2.0 Programming Guide.
//
#ifndef ESUTIL_H
#define ESUTIL_H

///
//  Includes
//
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <list>



/// esCreateWindow flag - RGB color buffer
#define ES_WINDOW_RGB           0
/// esCreateWindow flag - ALPHA color buffer
#define ES_WINDOW_ALPHA         1 
/// esCreateWindow flag - depth buffer
#define ES_WINDOW_DEPTH         2 
/// esCreateWindow flag - stencil buffer
#define ES_WINDOW_STENCIL       4
/// esCreateWindow flag - multi-sample buffer
#define ES_WINDOW_MULTISAMPLE   8
/// esCreateWindow flag - EGL_POST_SUB_BUFFER_NV supported.
#define ES_WINDOW_POST_SUB_BUFFER_SUPPORTED 16

///
// Types
//

///
//  Extensions
//

//extern PFNEGLPOSTSUBBUFFERNVPROC eglPostSubBufferNV;

extern PFNGLDELETEFENCESNVPROC glDeleteFencesNV;
extern PFNGLGENFENCESNVPROC glGenFencesNV;
extern PFNGLGETFENCEIVNVPROC glGetFenceivNV;
extern PFNGLISFENCENVPROC glIsFenceNV;
extern PFNGLFINISHFENCENVPROC glFinishFenceNV;
extern PFNGLSETFENCENVPROC glSetFenceNV;
extern PFNGLTESTFENCENVPROC glTestFenceNV;

struct DrawFunc {
	virtual void Draw() const {}
	virtual ~DrawFunc() {}
};

struct UpdateFunc {
	virtual void Update(float dt) const {}
	virtual ~UpdateFunc() {}
};

struct KeyFunc {
	virtual void Key(unsigned char, int, int) const {}
	virtual ~KeyFunc() {}
};

class ESContext
{
	std::list<DrawFunc> _draws;
	std::list<UpdateFunc> _updates;
	std::list<KeyFunc> _keys;
public:
   void*       _userData;
   GLint       _width;
   GLint       _height;
   EGLNativeWindowType  _hWnd;
   EGLDisplay  _eglDisplay;
   EGLContext  _eglContext;
   EGLSurface  _eglSurface;

	void DrawAll();
	void UpdateAll(float dt);
	void KeysAll(unsigned char c, int x, int y);
	bool Create(LPCTSTR title, GLint width, GLint height, GLuint flags );
	virtual bool WinCreate(LPCTSTR title) = 0;
	

	void RegisterDrawFunc(const DrawFunc& f);
	void RegisterUpdateFunc(const UpdateFunc&  f);
	void RegisterKeyFunc (const KeyFunc&  f);

	ESContext();
	~ESContext();
	bool CreatePlatformContext(LPCTSTR title);
	void Resize(int width, int height);
	void MainLoop();
} ;

extern ESContext* g_ESContext;

namespace GLES2 {
	 struct ESMatrix {
		GLfloat   m[4][4];
		ESMatrix() {
			memset(m, 0x0, sizeof(GLfloat)*4*4);
			m[0][0] = 1.0f;
			m[1][1] = 1.0f;
			m[2][2] = 1.0f;
			m[3][3] = 1.0f;
		}
	} ;
	void LogMessage ( const char *formatStr, ... );
	GLuint  LoadShader ( GLenum type, const char *shaderSrc );
	GLuint  LoadProgram ( const char *vertShaderSrc, const char *fragShaderSrc );
	int  GenSphere ( int numSlices, float radius, GLfloat **vertices, GLfloat **normals, GLfloat **texCoords, GLushort **indices );
	int  GenCube ( float scale, GLfloat **vertices, GLfloat **normals,  GLfloat **texCoords, GLushort **indices );
	//char*  LoadTGA ( char *fileName, int *width, int *height );
	void  Scale(ESMatrix *result, GLfloat sx, GLfloat sy, GLfloat sz);
	void  Translate(ESMatrix *result, GLfloat tx, GLfloat ty, GLfloat tz);
	void  Rotate(ESMatrix *result, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	void  Frustum(ESMatrix *result, float left, float right, float bottom, float top, float nearZ, float farZ);
	void  Perspective(ESMatrix *result, float fovy, float aspect, float nearZ, float farZ);
	void  Ortho(ESMatrix *result, float left, float right, float bottom, float top, float nearZ, float farZ);
	void  MatrixMultiply(ESMatrix *result, ESMatrix *srcA, ESMatrix *srcB);
	void  MatrixLoadIdentity(ESMatrix *result);
};

#endif // ESUTIL_H
