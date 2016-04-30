
#ifndef HEAP
#define HEAP

#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class LessCompare // MaxHeap
{
public:
	bool operator () (const T& node1, const T& node2)
	{
		return node1 < node2;
	}
};

template <typename T>
class MoreCompare //MinHeap
{
public:
	bool operator () (const T& node1, const T& node2)
	{
		return node1 > node2;
	}
};

template<class T, class Comp>
class Heap {
    T *h;
    int capacity;
    int size;
    Comp comp;

    int parentOf (int index)
    {
        return (index-1)/2;
    }

    int leftSonOf (int index)
    {
        return index*2+1;
    }

    int rightSonOf (int index)
    {
        return index*2+2;
    }

    T valueOf (int index)
    {
        return h[index];
    }

    void resize (int newCapacity)
    {
        T *newHeap = new T[newCapacity];
        int i;
        for (i=0; i<capacity && i<newCapacity; i++)
            newHeap[i] = h[i];

        delete[] h;

        h = newHeap;
        capacity = newCapacity;
    }

    void pushUp (int index)
    {
        if (!index) return;

        if (comp(h[parentOf(index)],h[index]))
            swap(h[index],h[parentOf(index)]);
        else return;

        pushUp(parentOf(index));
    }

    int bestSonOf (int index) // va returna cel mai mare fiu; 0 daca nu exista
    {
        if (rightSonOf(index) >= size)
        {
            if (leftSonOf(index) >= size) return 0;
            return leftSonOf(index);

        }
        if ( comp(h[leftSonOf(index)], h[rightSonOf(index)]) ) // alege dreapta
        {
            return rightSonOf(index);
        }

        return leftSonOf(index);
    }

    void pushDown (int index)
    {
        int i = bestSonOf(index);

        if (!i) return;
        if ( comp(h[index], h[i]) )
        {
            swap(h[index],h[i]);
            pushDown(i);
        }
    }

public:
    Heap()
	{
		this->capacity = 1;
		this->size = 0;
		h = new T[1];
	}

	Heap(int capacity)
	{
		this->size = 0;
		this->capacity = capacity;
		h = new T[capacity];
	}

	~Heap()
	{
		delete[] h;
	}

    void insert(const T& elem)
    {
        if (size==capacity)
            resize(2*capacity);

        h[size] = elem;
        pushUp(size);
        size++;
    }

    T front() // Returneaza elementul din varful heap-ului dar NU il sterge
    {
        if (!size)
        {
            throw runtime_error ("Heap::front called on empty Heap!");
        }
        return h[0];
    }

    T pop() // Returneaza elementul din varful heap-ului si il sterge din heap
    {
        if (!size)
        {
            throw runtime_error ("Heap::pop called on empty Heap!");
        }

        swap(h[0],h[size-1]);
        size--;
        pushDown(0);

        return h[size];
    }

    bool empty()
    {
        return size == 0;
    }

    void print()
    {
        int i;
        cout<<"Continut:";
        for (i=0; i<size; i++) cout<<" "<<h[i];
        cout<<endl;
    }

};

#endif // HEAP
