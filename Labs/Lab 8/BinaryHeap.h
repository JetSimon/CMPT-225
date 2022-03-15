/* 
 * BinaryHeap.h
 *
 * // To do: fill in the two blank spaces below
 * // Blank space 1: The choices are "minimum" or "maximum" 
 *                   (Todo: fill in the other blank spaces below.)
 * // Blank space 2: Refer to our lecture notes for the data structure used as CDT.
 * Description: __________ Binary Heap data collection ADT class. 
 *              __________ implementation.
 *
 * Class Invariant:  Always a __________ Binary Heap
 * 
 * Author: 
 *
 * Last Modification: March 2022
 *
 */   
 
#pragma once

#include <iostream>
#include "Event.h"
#include "EmptyDataCollectionException.h"   // To do: Feel free to recycle an exception class from Assignment 3.

using namespace std;


class BinaryHeap {

private:
    // To do: Add the data members here!
	int elementCount;

	Event elements[100];
	
	// Utility method - Recursively put the array back into a __________ Binary Heap.
	void reHeapUp(unsigned int indexOfBottom);

	// Utility method - Recursively put the array back into a __________ Binary Heap.
	void reHeapDown(unsigned int indexOfRoot);  
   
public:
	// Default Constructor
	BinaryHeap(); 
	
	// To do: If it needs a copy constructor, add it!
	// To do: If it needs a destructor, add it!
	
    // Description: Returns the number of elements in the Binary Heap.
    // Postcondition:  The Binary Heap is unchanged by this operation.
	// Time Efficiency: O(1)
    unsigned int getElementCount() const;

	// Description: Inserts newElement into the Binary Heap.
	//              It returns "true" if successful, otherwise "false".        
	// Postcondition: Remains a __________ Binary Heap after the insertion.
	// Time Efficiency: O(log2 n)
	bool insert(Event& newElement);
	   
	// Description: Removes (but does not return) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: Remains a __________ Binary Heap after the removal.	
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(log2 n)
	void remove();

	// Description: Retrieves (but does not remove) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: This Binary Heap is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(1) 
	Event retrieve() const;

	// For Testing Purposes
	// Description: Prints the content of "this". 
	friend ostream & operator<<(ostream & os, const BinaryHeap& rhs);
   
}; // end BinaryHeap