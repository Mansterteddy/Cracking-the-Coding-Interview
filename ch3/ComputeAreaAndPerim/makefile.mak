TARGETS = ComputeAreaAndPerim.exe
CC = cl
CCFLAGS = /Zi /EHsc /GR /GZ

all:	$(TARGETS)

ComputeAreaAndPerim.exe:	ComputeAreaAndPerim.obj Circle.obj Rectangle.obj \
Rt_Triangle.obj Parallelogram.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

ComputeAreaAndPerim.obj:	ComputeAreaAndPerim.cpp Circle.h Rectangle.h \
Rt_Triangle.h Shape.h Parallelogram.obj
	$(CC) $(CCFLAGS) /c ComputeAreaAndPerim.cpp

Circle.obj:	Circle.cpp Circle.h Shape.h
	$(CC) $(CCFLAGS) /c Circle.cpp

Rectangle.obj:	Rectangle.cpp Rectangle.h Shape.h
	$(CC) $(CCFLAGS) /c Rectangle.cpp

Rt_Triangle.obj:	Rt_Triangle.cpp Rt_Triangle.h Shape.h
	$(CC) $(CCFLAGS) /c Rt_Triangle.cpp

Parallelogram.obj:	Parallelogram.cpp Parallelogram.h Rectangle.h Shape.h
	$(CC) $(CCFLAGS) /c Parallelogram.cpp

.PHONY:	clean

clean:
	del *.obj
	del *.exe
	del *.pdb
	del *.ilk
