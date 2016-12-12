all:	Airplanes.exe

CCFLAGS = /Zi /EHsc /GR /GZ
CC = cl

Airplanes.exe:	Airplanes.cpp Airplanes.h
	$(CC) $(CCFLAGS) /Fe$@ Airplanes.cpp

clean:
	del *.obj
	del *.exe
	del *.pdb
	del *.ilk
