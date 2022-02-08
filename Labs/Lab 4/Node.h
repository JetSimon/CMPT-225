/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 
 * Author: 
 */
 
template <class ElementType>
class Node
{
public:

	// Public data members - Why are the data members public?
	ElementType data;     // The data in the node
	Node* next;   // Pointer to next node
	
	// Constructors
	Node();
	Node(ElementType theData);
	Node(ElementType theData, Node* theNextNode);

}; // end Node

#include <cstdio>  // Needed for NULL

template <class ElementType>
Node<ElementType>::Node()
{
	next = NULL;
}

template <class ElementType>
Node<ElementType>::Node(ElementType theData)
{
	data = theData;
	next = NULL;
}

template <class ElementType>
Node<ElementType>::Node(ElementType theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;
}

// end Node.cpp