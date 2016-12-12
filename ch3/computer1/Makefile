TARGETS = test_Computer.exe
CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

test_Computer.exe:	test_Computer.o Computer.o
	$(CC) $(CCFLAGS) -o $@ $^

test_Computer.o:	test_Computer.cpp Computer.h Lap_Top.h
	$(CC) $(CCFLAGS) -c test_Computer.cpp


Computer.o:	Computer.cpp Computer.h Lap_Top.h
	$(CC) $(CCFLAGS) -c Computer.cpp

.PHONY:	clean

clean:
	del *.o
	del *.exe
