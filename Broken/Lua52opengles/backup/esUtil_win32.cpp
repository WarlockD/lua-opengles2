//
// Book:      OpenGL(R) ES 2.0 Programming Guide
// Authors:   Aaftab Munshi, Dan Ginsburg, Dave Shreiner
// ISBN-10:   0321502795
// ISBN-13:   9780321502797
// Publisher: Addison-Wesley Professional
// URLs:      http://safari.informit.com/9780321563835
//            http://www.opengles-book.com
//

// esUtil_win32.c
//
//    This file contains the Win32 implementation of the windowing functions. 


///
// Includes
//

#include <windows.h>
#include "esUtil.h"

//////////////////////////////////////////////////////////////////
//
//  Private Functions
//
//

///
//  ESWindowProc()
//
//      Main window procedure
//
LRESULT WINAPI ESWindowProc ( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) 
{
   LRESULT  lRet = 1; 

   switch (uMsg) 
   { 
      case WM_CREATE:
         break;

      case WM_SIZE:
         {
            ESContext *esContext = (ESContext*)(LONG_PTR) GetWindowLongPtr ( hWnd, GWL_USERDATA );
            if ( esContext ) {
               esContext->_width = LOWORD( lParam );
               esContext->_height = HIWORD( lParam );
               InvalidateRect( esContext->_hWnd, NULL, FALSE );
            }
         }

      case WM_PAINT:
         {
            ESContext *esContext = (ESContext*)(LONG_PTR) GetWindowLongPtr ( hWnd, GWL_USERDATA );
            
            if ( esContext )
			{
				esContext->DrawAll();
				ValidateRect( esContext->_hWnd, NULL );
			}
         }
         break;

      case WM_DESTROY:
         PostQuitMessage(0);             
         break; 
      
      case WM_CHAR:
         {
            POINT      point;
            ESContext *esContext = (ESContext*)(LONG_PTR) GetWindowLongPtr ( hWnd, GWL_USERDATA );
            
            GetCursorPos( &point );

            if ( esContext  )
				esContext->KeysAll((unsigned char) wParam, 
		                             (int) point.x, (int) point.y );
		 }
         break;
         
      default: 
         lRet = DefWindowProc (hWnd, uMsg, wParam, lParam); 
         break; 
   } 

   return lRet; 
}

//////////////////////////////////////////////////////////////////
//
//  Public Functions
//
//

///
//  WinCreate()
//
//      Create Win32 instance and window
//
//bool CreateContext(LPCTSTR title);
//	void MainLoop();
bool ESContext::CreatePlatformContext ( LPCTSTR title )
{
   WNDCLASS wndclass = {0}; 
   DWORD    wStyle   = 0;
   RECT     windowRect;
   HINSTANCE hInstance = GetModuleHandle(NULL);
   
   wndclass.style         = CS_OWNDC;
   wndclass.lpfnWndProc   = (WNDPROC)ESWindowProc; 
   wndclass.hInstance     = hInstance; 
   wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); 
   wndclass.lpszClassName = TEXT("opengles2.0");

   if (!RegisterClass (&wndclass) ) 
      return FALSE; 

   wStyle = WS_VISIBLE | WS_POPUP | WS_BORDER | WS_SYSMENU | WS_CAPTION | WS_SIZEBOX;
   
   // Adjust the window rectangle so that the client area has
   // the correct number of pixels
   windowRect.left = 0;
   windowRect.top = 0;
   windowRect.right = _width;
   windowRect.bottom = _height;

   AdjustWindowRect ( &windowRect, wStyle, FALSE );

   _hWnd = CreateWindow(
                         TEXT("opengles2.0"),
                         title,
                         wStyle,
                         0,
                         0,
                         windowRect.right - windowRect.left,
                         windowRect.bottom - windowRect.top,
                         NULL,
                         NULL,
                         hInstance,
                         NULL);

   // Set the ESContext* to the GWL_USERDATA so that it is available to the 
   // ESWindowProc
   SetWindowLongPtr (  _hWnd, GWL_USERDATA, (LONG) (LONG_PTR) this );

   if ( _hWnd == NULL )
      return GL_FALSE;

   ShowWindow ( _hWnd, TRUE );

   return GL_TRUE;
}

///
//  winLoop()
//
//      Start main windows loop
//

void ESContext::MainLoop()
{
   MSG msg = { 0 };
   int done = 0;
   DWORD lastTime = GetTickCount();
   
   while (!done)
   {
      int gotMsg = (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0);
      DWORD curTime = GetTickCount();
      float deltaTime = (float)( curTime - lastTime ) / 1000.0f;
      lastTime = curTime;

      if ( gotMsg )
      {
         if (msg.message==WM_QUIT)
         {
             done=1; 
         }
         else
         {
             TranslateMessage(&msg); 
             DispatchMessage(&msg); 
         }
      }
      else
         SendMessage( _hWnd, WM_PAINT, 0, 0 );

      // Call update function if registered
	  UpdateAll(deltaTime);
   }
}
