//arrayHeader.h
#ifndef ARRAYHEADER_H
#define ARRAYHEADER_H

#include <iostream>
using namespace std;

template <typename T>
class array
{
private:
    T *arr;
    int size;
    int capacity;

public:
    array(int initialCapacity = 10)
    {
        capacity = initialCapacity;
        arr = new T[capacity];
        size = 0;
    }

    void insert(T item)
    {
        if (size < capacity)
        {
            arr[size++] = item;
            cout << "Item inserted." << endl;
        }
        else
        {
            cout << "Array is full. Cannot insert." << endl;
        }
    }

    void remove()
    {
        if (size > 0)
        {
            size--;
            cout << "Item removed." << endl;
        }
        else
        {
            cout << "Array is empty. Cannot remove." << endl;
        }
    }

    void display()
    {
        if (size > 0)
        {
            cout << "Array contents: ";
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Array is empty." << endl;
        }
    }

    ~array()
    {
        delete[] arr;
    }
};

#endif