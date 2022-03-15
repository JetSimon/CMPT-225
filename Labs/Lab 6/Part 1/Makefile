all: ptd

ptd: Patient_Test_Driver.o Patient.o
	g++ -Wall Patient_Test_Driver.o Patient.o -o ptd

Patient_Test_Driver.o: Patient_Test_Driver.cpp Patient.h
	g++ -Wall -c Patient_Test_Driver.cpp

Patient.o: Patient.h Patient.cpp
	g++ -Wall -c Patient.cpp

clean:
	rm -f ptd *.o