TARGETS = test_Food.exe
CC = cl
CCFLAGS = /Zi /EHsc /GR /GZ

all:	$(TARGETS)

test_Food.exe:	test_Food.obj Vegetable.obj
	$(CC) $(CCFLAGS) /Fe$@ $**
 

test_Food.obj: test_Food.cpp Vegetable.h Food.h
	$(CC) $(CCFLAGS) /c /Fo$@ test_Food.cpp

Vegetable.obj: Vegetable.cpp Vegetable.h Food.h
	$(CC) $(CCFLAGS) /c /Fo$@ Vegetable.cpp


clean:
	del *.obj
	del *.exe
	del *.pdb
	del *.ilk
