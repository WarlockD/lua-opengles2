I wanted to play with opengles 2.0 in a faster way than recompile-ring in C and since I can't seem to find anyone doing this I thought I might as well get it out there.

Right now its Alpha.  As of this message it dosn't compile.  Right now I am building some buffer utility's to move array data between lua and opengles.

Its using the PowerVR DLL files right now but eventually I will compile it with googles angleproject straight.

Also I am developing it on windows but I will clean up the source once I feel its working well enough for other platforms.  I doubt you want to run this on a google or iphone as its type checking the calls.  Eventually I will put debug tags to remove the type checking but for right now its slooow.

Based of Lua 5.2