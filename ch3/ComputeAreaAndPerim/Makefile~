TARGETS = ComputeAreaAndPerim
CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

ComputeAreaAndPerim:	ComputeAreaAndPerim.o Circle.o Rectangle.o \
Rt_Triangle.o Parallelogram.o
	$(CC) $(CCFLAGS) -o $@ $^

ComputeAreaAndPerim.o:	ComputeAreaAndPerim.cpp Circle.h Rectangle.h \
Rt_Triangle.h Shape.h Parallelogram.o
	$(CC) $(CCFLAGS) -c $<

Circle.o:	Circle.cpp Circle.h Shape.h
	$(CC)  $(CCFLAGS) -c $<

Rectangle.o:	Rectangle.cpp Rectangle.h Shape.h
	$(CC)  $(CCFLAGS) -c $<

Rt_Triangle.o:	Rt_Triangle.cpp Rt_Triangle.h Shape.h
	$(CC) $(CCFLAGS) -c $<

Parallelogram.o:	Parallelogram.cpp Parallelogram.h Rectangle.h Shape.h
	$(CC) $(CCFLAGS) -c $<

.PHONY: clean

clean:
	rm -f *.o
	rm -f $(TARGETS)
