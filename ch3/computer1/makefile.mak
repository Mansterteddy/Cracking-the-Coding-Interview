TARGETS = test_Computer.exe
CC = cl
CCFLAGS = /Zi /EHsc /GR /GZ

all:	$(TARGETS)

test_Computer.exe:	test_Computer.obj Computer.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

test_Computer.obj:	test_Computer.cpp Computer.h Lap_Top.h
	$(CC) $(CCFLAGS) /c test_Computer.cpp


Computer.obj:	Computer.cpp Computer.h Lap_Top.h
	$(CC) $(CCFLAGS) /c Computer.cpp

.PHONY:	clean

clean:
	del *.obj
	del *.exe
	del *.pdb
	del *.ilk
