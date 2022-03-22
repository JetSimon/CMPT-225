#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"

using namespace std;

int main()
{
    BST* bst = new BST();

    string filename = "myDataFile.txt";
    string aLine;
    ifstream myfile(filename);

    if (myfile.is_open())
    {
        while (getline(myfile, aLine))
        {
            bst->insert(stoi(aLine));
        }
        myfile.close();
    }

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