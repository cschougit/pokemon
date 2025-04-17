Cygwin required install:

Qt5:
"qt5-base"  for run-time
"qt5-devel" for qmake

X11: QT5 need X11 library for initialize GUI
"xorg-server"
"xinit"
"xterm"

Step:
1. edit xxx.pro
2. qmake xxx.pro
3. make (here maybe need to manually remove "-lGl -lpthread" from "Makefile")
4. startxwin -- -multiwindow
5. export DISPLAY=:0.0
6. ./xxx.exe
