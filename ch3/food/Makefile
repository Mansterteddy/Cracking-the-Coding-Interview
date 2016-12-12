TARGETS = test_Food.exe
CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

test_Food.exe:	test_Food.o Vegetable.o
	$(CC) $(CCFLAGS) -o $@ $^
 
%.o:	%.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^

clean:
	del *.o
	del *.exe
