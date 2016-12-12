TARGETS = test_Computer.exe test_Computer2.exe
CC = cl
CCFLAGS = /Zi /EHsc /GR /GZ

all:	$(TARGETS)

test_Computer.exe:	test_Computer.obj Computer.obj Lap_Top.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

test_Computer.obj:	test_Computer.cpp Computer.h Lap_Top.h
	$(CC) $(CCFLAGS) /c test_Computer.cpp

Computer.obj:	Computer.cpp Computer.h
	$(CC) $(CCFLAGS) /c Computer.cpp

Lap_Top.obj:	Lap_Top.cpp Lap_Top.h Computer.h
	$(CC) $(CCFLAGS) /c Lap_Top.cpp

test_Computer2.exe:	test_Computer2.obj Computer.obj Lap_Top.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

test_Computer2.obj:	test_Computer2.cpp Computer.h Lap_Top.h
	$(CC) $(CCFLAGS) /c test_Computer2.cpp
 
clean:
	del *.obj
	del *.exe
	del *.pdb
	del *.ilk
