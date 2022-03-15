all: test

test: EmptyDataCollectionException.o BinaryHeap.o Event.o TestDriver.o 
	g++ -Wall -o lab TestDriver.o EmptyDataCollectionException.o

TestDriver.o: TestDriver.cpp BinaryHeap.h Event.h
	g++ -Wall -c TestDriver.cpp
		
BinaryHeap.o: BinaryHeap.h BinaryHeap.cpp
	g++ -Wall -c BinaryHeap.cpp

Event.o: Event.h Event.cpp
	g++ -Wall -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f translate *.o