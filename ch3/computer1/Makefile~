TARGETS = test_Computer EX3P1P1
CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

test_Computer:	test_Computer.o Computer.o
	$(CC) $(CCFLAGS) -o $@ $^

test_Computer.o:	test_Computer.cpp Computer.h Lap_Top.h
	$(CC) $(CCFLAGS) -c test_Computer.cpp


Computer.o:	Computer.cpp Computer.h Lap_Top.h
	$(CC) $(CCFLAGS) -c Computer.cpp

EX3P1P1:	EX3P1P1.o Computer.o
	$(CC) $(CCFLAGS) -o $@ $^

EX3P1P1.o:	EX3P1P1.cpp Computer.h Lap_Top.h
	$(CC) $(CCFLAGS) -c EX3P1P1.cpp
 
.PHONY:	clean

clean:
	rm -f *.o
	rm -f $(TARGETS)
