/*
 * List.h - Header of the List class
 *
 * Class Description: A data collection List ADT class.
 *
 * Creation Date:
 * Author:
 */

// #pragma once -> This preprocessor statement is equivalent to: 
//                 #ifndef _LIST 
//                 #define _LIST
//                 and it means: do not include the preprocessor statements below me more than once.
#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <class ElementType>
class List{

private:
 /*
  * Note that this is a link-based implementation of a data collection
  * List ADT class. Its underlying data structure is a singly-headed
  * singly-linked list (SHSL).
  */

	Node<ElementType> *head;                 // Pointer to the first node in the list
	unsigned int elementCount;  // Number of elements currently stored in the list.

public:
	// Constructors and Destructors


	/* Generally, if a class makes use of dynamic memory allocation,
	 * we should provide at least two constructors: a default constructor and
	 * a copy constructor that creates a deep copy of the given object.
	 */
	 
	 
	// Description: Default constructor
	List();


	/* Note that the compiler will generate a copy constructor automatically.
	 * However, this constructor only creates a SHALLOW COPY (so would only copy the
	 * elementCount and head variables). In this case, this would NOT CREATE A
	 * NEW LIST object, just a new reference to "this" List object.
	 * It is therefore necessary to write a constructor that makes a DEEP COPY
	 * if our class makes use of dynamically allocated memory.
	 */

	/* Also note the parameter. C++ functions use pass-by-value by
	 * default. This means that the functions make copies of the given
	 * arguments. This is inefficient (particularly for large objects).
	 * Therefore it is normal to pass a reference, (using '&') to the parameter.
     * Also, if the parameter must not be changed,
	 * it is good practice to make it "const", which prevents it from being changed.
	 */
	// Description: Copy constructor to copy an existing List object.
	List(const List& lst); //copy constructor


	/* The destructor is responsible for deleting any memory that was dynamically
	 * allocated by an object. If there is no such memory, no destructor needs to
	 * be created (the compiler automatically creates one). Because this class
	 * uses memory dynamically allocated (and pointers) when new elements are
     * inserted into the List (instantiate object of Node class), it is necessary to write a destructor.
     * Destructors are identified by the '~' preceding the class name.
	 * There can be only one destructor for a class, and it cannot have parameters.
	 */
	 // Description: Destruct a List object, releasing heap-allocated memory.
	~List();//destructor


	/**************************************************************************/
	// List Operations
	//
	// Description: Add an element (newElement) to the list.
	// Postcondition: newElement is inserted at the end of the list.
	void add(ElementType newElement);


	/*
	 * Note that there is some debate about whether or not this type of
	 * method belongs in a class. The argument (briefly) is that a class
	 * shouldn't be responsible for I/O by "displaying" itself as it cannot
	 * foresee how it is to be displayed (in a TUI or GUI environment).
	 * However, such method eases testing.
	 * For testing purpose, unless required by client in problem statement.
	 * Could also overload operator<<.
	 */
	 // Description: Prints the contents of the list from the first to the last element.
	 void printList();

	 int getElementCount();

}; // end of header file of List class


// Constructors and Destructors


// Description: Default constructor
template <class ElementType>
List<ElementType>::List(){
	elementCount = 0;
	head = NULL;
}


// Description: Copy constructor to copy an existing List object.
template <class ElementType>
List<ElementType>::List(const List& lst){
	elementCount = lst.elementCount;
	//head = lst.head; //shallow copy - you need to fix this!
	head = new Node<ElementType>(lst.head->data);
	Node<ElementType> *currentOther = lst.head;
	Node<ElementType> *current = head;

	

	while(currentOther != NULL)
	{
		if(currentOther->next != NULL)
			current->next = new Node<ElementType>(currentOther->next->data);
		currentOther = currentOther->next;
		current = current->next;
	}
}

// Description: Destruct a List object, releasing heap-allocated memory.
template <class ElementType>
List<ElementType>::~List(){
	Node<ElementType>* next = head;
	while(next != NULL)
	{
		Node<ElementType>* toDel = next;
		next = toDel -> next;
		delete toDel;
	}
}

/**************************************************************************/
// List Operations
//
// Description: Add an element (newElement) to the list.
// Postcondition: newElement is inserted at the end of the list.
template <class ElementType>
void List<ElementType>::add(ElementType newElement){
	Node<ElementType> *newNode = new Node<ElementType>(newElement); //new Node with x

	// Check to see if list is empty
	if (head == NULL){
		// Make new Node the new head
		head = newNode;
	}else{
		// Move to the end of the list
		Node<ElementType>* current = head;
		while (current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
	elementCount++;
}


/*
 * Note that there is some debate about whether or not this type of
 * method belongs in a class. The argument (briefly) is that a class
 * shouldn't be responsible for I/O by "displaying" itself as it cannot
 * foresee how it is to be displayed (in a TUI or GUI environment).
 * However, such method eases testing.
 * For testing purpose, unless required by client in problem statement.
 * Could also overload operator<<.
 */
 // Description: Prints the contents of the list from the first to the last element.
template <class ElementType>
void List<ElementType>::printList(){
	Node<ElementType> *current = head;
	cout << "{"; //Nice format!
	// Traverse the list
	while (current != NULL){
		cout << current -> data; // Print data
		current = current -> next; // Go to next Node
		if (current != NULL){
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "}"; // Don't print a newline - it might not be wanted
}

template <class ElementType>
int List<ElementType>::getElementCount()
{
	return elementCount;
}


// end of implementation file of List class
