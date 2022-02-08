#include <iostream>
#include "Circle.h"
using namespace std;

int main()
{
    int size;
    int elements = 0;
    cout << "enter array size: " << endl;
    cin >> size;
    Circle *arr = new Circle[size];

    bool inputting = true;

    while(inputting && elements < size)
    {
        int x,y;
        double radius;
        char done;
        cout << "Are you done (Y/n): ";
        cin >> done;

        if(done == 'Y')
        {
            inputting = false;
        }
        else if(done == 'n')
        {
            cout << "Enter x y radius seperated by space: ";
            cin >> x;
            cin >> y;
            cin >> radius;
            Circle c = Circle(x,y,radius);
            arr[elements] = c;
            elements++;
        }
    }

    for(int i = 0; i < elements; i++) arr[i].displayCircle();
    for(int i = 0; i < size - elements; i++) cout << "This cell is empty." << endl;

    delete[] arr;
}