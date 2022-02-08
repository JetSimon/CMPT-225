/* 
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Jet Simom
 * Date: Feb 8 2022
 */

#include "Stack.h"


// Description: Constructor
Stack::Stack() {
    elementCount = 0;
}

// Description: Returns true if Stack empty.
bool Stack::isEmpty() const {
    return elementCount == 0;
} 

// Description: Insert element x to the top of Stack.
void Stack::push(int x) {
    arr[elementCount++] = x;
} 

// Description: Remove and return element at the top of Stack.
int Stack::pop() {
    return arr[--elementCount];
} 

// Description: Removes and returns the max element.
//              In case of duplicated max, take the one closest to the top.
// Precondition: Stack nonempty
// Postcondition: Order of remaining elements is preserved
int Stack::removeMax() {
    int maxIndex = 0;
    int maxElement = arr[maxIndex];
    //Go through each element keep track of the max index with closer to top so use > not >=
    for(int i = 1; i < elementCount; i++)
    {
        if(arr[i] > arr[maxIndex])
        {
            maxIndex = i;
            maxElement = arr[maxIndex];
        }
    }

    for(int i = 0; i < elementCount; i++)
    {
        if(i <= maxIndex)
        {
            arr[i] = arr[i];
        }
        else
        {
            arr[i-1] = arr[i];
        }
    } 

    arr[elementCount-1] = -1;
    elementCount--;

    return maxElement;
} 


