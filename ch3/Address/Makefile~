all:	Test_Address 

CCFLAGS = -g -Wall -pedantic
CC	= g++



Test_Address:	Test_Address.o US_Address.o German_Address.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Address.o:	Test_Address.cpp Address.h
	$(CC) $(CCFLAGS) -c $<

US_Address.o:	US_Address.cpp Address.h
	$(CC) $(CCFLAGS) -c $<

German_Address.o:	German_Address.cpp Address.h
	$(CC) $(CCFLAGS) -c $<

clean:
	rm *.o
	rm Test_Address
