TARGETS = test_Food
CC = g++
CCFLAGS = -g -Wall -pedantic

all: $(TARGETS)

test_Food:	test_Food.o Vegetable.o
	$(CC) $(CCFLAGS) -o $@ $^ 
 
%.o:	%.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^

clean:
	rm -f *.o
	rm -f $(TARGETS)
