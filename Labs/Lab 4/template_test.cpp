#include <iostream>
#include <cstring>
#include "List.h"

using namespace std;

int main() {
  List<int> intList = List<int>();
  /* Test Case 1 */
// An empty 'int' List has already been instantiated - testing the default constructor.
// Confirm this by printing the List (and testing the method printList() in doing so).
// We can also confirm the List is empty by calling getElementCount():
cout << "Test Case 1: Creating an empty List of int's." << endl;
cout << "Expected Result: The List is empty." << endl; 
cout << "Actual Result: Is the List empty? elementCount = " << intList.getElementCount() << endl;
cout << "elements of intList: ";
intList.printList(); 

/* Test Case 2 */
cout << "Test Case 2: Testing add() method - Adding the element 3 to the empty List." << endl;
intList.add(3);
// Confirm add(3) was successful by printing the List and the returned value of getElementCount( ) which should be 1.
cout << "Expected Result: The List has one element: 3." << endl;
cout << "Actual Result: Does the List contain the element 3? elementCount = " << intList.getElementCount() << endl; 	
cout << "elements of intList: ";
intList.printList(); 
  return 0;
  
}