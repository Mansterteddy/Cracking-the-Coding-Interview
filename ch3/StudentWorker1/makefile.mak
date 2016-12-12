TARGETS = Test_Employee.exe Test_Student.exe Test_Address.exe \
Test_Student_Worker.exe
CC = cl
CCFLAGS = /Zi /EHsc /GR /GZ

all:	$(TARGETS)

Test_Student_Worker.exe:	Test_Student_Worker.obj Student_Worker.obj \
German_Address.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

Test_Employee.exe:	Test_Employee.obj Employee.obj German_Address.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

Test_Student.exe:	Test_Student.obj Student.obj German_Address.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

Test_Address.exe:	Test_Address.obj German_Address.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

Test_Address.obj:	Test_Address.cpp Address.h
	$(CC) $(CCFLAGS) /c Test_Address.cpp

German_Address.obj:	German_Address.cpp Address.h
	$(CC) $(CCFLAGS) /c German_Address.cpp

Employee.obj:	Employee.cpp Employee.h Address.h
	$(CC) $(CCFLAGS) /c Employee.cpp

Student.obj:	Student.cpp Student.h Address.h
	$(CC) $(CCFLAGS) /c Student.cpp

Test_Student.obj:	Test_Student.cpp Student.h Address.h
	$(CC) $(CCFLAGS) /c Test_Student.cpp

Test_Employee.obj:	Test_Employee.cpp Employee.h Address.h
	$(CC) $(CCFLAGS) /c Test_Employee.cpp

Student_Worker.obj:	Student_Worker.cpp Student.h Employee.h \
Student_Worker.h Address.h
	$(CC) $(CCFLAGS) /c Student_Worker.cpp

Test_Student_Worker.obj: Test_Student_Worker.cpp Student_Worker.h Student.h \
Employee.h Address.h
	$(CC) $(CCFLAGS) /c Test_Student_Worker.cpp

clean:
	del *.exe
	del *.obj
	del *.pdb
	del *.ilk
