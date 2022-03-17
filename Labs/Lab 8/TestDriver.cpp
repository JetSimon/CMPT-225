using namespace std;
#include <iostream>
#include "BinaryHeap.h"
#include "Event.h"

int main()
{
    BinaryHeap heap;

    for(int i = 1; i < 10; i++)
    {
        Event e;
        e.setTime(i);
        heap.insert(e);

        cout << "HEAP HAS:" << endl;

        cout << heap;
    }

    Event e1;
    e1.setTime(4);
    heap.insert(e1);
    cout << "HEAP HAS:" << endl;
    cout << heap;

    Event e2;
    e2.setTime(0);
    heap.insert(e2);
    cout << "HEAP HAS:" << endl;
    cout << heap;

    for(int i = 1; i < 10; i++)
    {
        heap.remove();
        cout << "HEAP HAS:" << endl;
        cout << heap;
    }
    
    return 0;
}