TARGETS = test_Computer test_Computer2
CC = g++
CCFLAGS = -g -Wall -pedantic

all: $(TARGETS)

test_Computer:	test_Computer.o Computer.o Lap_Top.o
	$(CC) $(CCFLAGS) -o $@ $^

test_Computer.o:	test_Computer.cpp Computer.h Lap_Top.h
	$(CC) $(CCFLAGS) -c test_Computer.cpp

Computer.o:	Computer.cpp Computer.h
	$(CC) $(CCFLAGS) -c Computer.cpp

Lap_Top.o:	Lap_Top.cpp Lap_Top.h Computer.h
	$(CC) $(CCFLAGS) -c Lap_Top.cpp

test_Computer2:	test_Computer2.o Computer.o Lap_Top.o
	$(CC) $(CCFLAGS) -o $@ $^

test_Computer2.o:	test_Computer2.cpp Computer.h Lap_Top.h
	$(CC) $(CCFLAGS) -c test_Computer2.cpp
 
clean:
	rm -f *.o
	rm -f $(TARGETS)
