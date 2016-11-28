To use this project, you need to have wxWidgets installed and built for shared libraries. Use following command of mingw in path: C:/Program Files/wxWidgets/build/msw
mingw32-make -f makefile.gcc SHARED=1 UNICODE=1 BUILD=release clean //for cleaning up
mingw32-make -f makefile.gcc SHARED=1 UNICODE=1 BUILD=release // for building with shared libraries

You'll also have to setup libraries and library path:
libraries for input:
wxmsw31u_xrc
wxmsw31u_html
wxmsw31u_adv
wxmsw31u_core
wxbase31u_xml
wxbase31u_net
wxbase31u
wxtiff
wxjpeg
wxpng
wxzlib
kernel32
user32
wxregexu
wxexpat
winmm
comctl32
rpcrt4
wsock32
odbc32
library path:
C:/Program Files/wxWidgets/lib/gcc_dll

Also, you'll have to put the dll's into the same folder(if not configured otherwise) as the executable built by your ide for the program to work.

#Tests
The current test project is only setup for UI test(ie. tests for UI methods). An additional CUTE Library Test projects needs to be set for Projects, that provide additional functionality, which are then used in the UI(this lib would have to be built and linked into the UI proj)