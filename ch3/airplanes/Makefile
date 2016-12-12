all:	Airplanes.exe

CCFLAGS = -g -Wall -pedantic
CC = g++

Airplanes.exe:	Airplanes.cpp Airplanes.h
	$(CC) $(CCFLAGS) -o $@ $<

clean:
	del *.o
	del *.exe
