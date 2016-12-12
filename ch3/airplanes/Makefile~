all:	Airplanes

CCFLAGS = -g -Wall -pedantic
CC = g++

Airplanes:	Airplanes.cpp Airplanes.h
	$(CC) $(CCFLAGS) -o $@ $<

clean:
	rm -f *.o
	rm Airplanes
