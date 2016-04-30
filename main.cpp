#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
    Heap<int, LessCompare<int> > myHeap; // maxHeap

    myHeap.insert(19);
    myHeap.insert(36);
    myHeap.insert(17);
    myHeap.insert(1);
    myHeap.insert(3);
    myHeap.insert(7);
    myHeap.insert(25);
    myHeap.insert(2);
    myHeap.insert(100);

    myHeap.print();

    cout << "Elementele in ordine descrescatoare:\n";

    cout << myHeap.front() << endl;
    myHeap.pop();

    while (!myHeap.empty()){
        cout << myHeap.pop() << endl;
    }

    return 0;
}
