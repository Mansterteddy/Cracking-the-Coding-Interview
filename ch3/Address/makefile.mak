all:	Test_Address.exe

CCFLAGS = /Zi /EHsc /GR /GZ
CC = cl



Test_Address.exe:	Test_Address.obj US_Address.obj German_Address.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

Test_Address.obj:	Test_Address.cpp Address.h
	$(CC) $(CCFLAGS) /c Test_Address.cpp

US_Address.obj:	US_Address.cpp Address.h
	$(CC) $(CCFLAGS) /c US_Address.cpp

German_Address.obj:	German_Address.cpp Address.h
	$(CC) $(CCFLAGS) /c German_Address.cpp

clean:
	del *.obj
	del *.exe
	del *.pdb
	del *.ilk
