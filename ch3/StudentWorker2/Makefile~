TARGETS = Test_Employee Test_Student Test_Address Test_Student_Worker
CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

Test_Student_Worker:	Test_Student_Worker.o Student_Worker.o \
US_Address.o German_Address.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Employee:	Test_Employee.o Employee.o US_Address.o German_Address.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Student:	Test_Student.o Student.o US_Address.o German_Address.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Address:	Test_Address.o US_Address.o German_Address.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Address.o:	Test_Address.cpp Address.h
	$(CC) $(CCFLAGS) -c Test_Address.cpp

US_Address.o:	US_Address.cpp Address.h
	$(CC) $(CCFLAGS) -c US_Address.cpp

German_Address.o:	German_Address.cpp Address.h
	$(CC) $(CCFLAGS) -c German_Address.cpp

Employee.o:	Employee.cpp Employee.h Address.h
	$(CC) $(CCFLAGS) -c Employee.cpp

Student.o:	Student.cpp Student.h Address.h
	$(CC) $(CCFLAGS) -c Student.cpp

Test_Student.o:	Test_Student.cpp Student.h Address.h
	$(CC) $(CCFLAGS) -c Test_Student.cpp

Test_Employee.o: Test_Employee.cpp Employee.h Address.h
	$(CC) $(CCFLAGS) -c Test_Employee.cpp

Student_Worker.o: Student_Worker.cpp Student.h Employee.h \
Student_Worker.h Address.h
	$(CC) $(CCFLAGS) -c Student_Worker.cpp


clean:	
	rm -f *.o
	rm -f $(TARGETS)