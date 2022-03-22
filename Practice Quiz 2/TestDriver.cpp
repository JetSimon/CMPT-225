#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    BST<int>* bst = new BST<int>();

    bst->insert(1);
    bst->insert(10);
    bst->insert(22);
    bst->insert(124);
    bst->insert(2);
    bst->insert(-2);
    bst->insert(3);

    cout << "Official element count: " << bst->getElementCount() << endl << "nodesCount: " << bst->nodesCount() << endl;

    cout << "Min element: " << bst->min() << endl;

    cout << "Even count: " << bst->evenCount() << endl;

    cout << "Odd count: " << bst->oddCount() << endl;

    cout << "Copies of 10: " << bst->duplicateCount(10) << endl;

    cout << "Tree height: " << bst->height() << endl;

    cout << "Sum: " << bst->sum() << endl;

    cout << "Average: " << bst->average() << endl;

    cout << "Reverse print:" << endl;
    
    bst->printInReverseOrder();

    return 0;
}