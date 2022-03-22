all: test

test: TestDriver.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o BST.h BSTNode.h
	g++ -Wall -o test TestDriver.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o

TestDriver.o: TestDriver.cpp
	g++ -Wall -c TestDriver.cpp

ElementDoesNotExistException.o: ElementDoesNotExistException.h ElementDoesNotExistException.cpp
	g++ -Wall -c ElementDoesNotExistException.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.h ElementAlreadyExistsException.cpp
	g++ -Wall -c ElementAlreadyExistsException.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f test *.o