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

int main()
{
    array<int> list;

    int ch, item;
    bool quit = false;

    do
    {
        cout << "====================================" << endl;
        cout << "Select an option:" << endl;
        cout << "1: Insert" << endl;
        cout << "2: Display" << endl;
        cout << "3: Remove" << endl;
        cout << "4: Exit" << endl;
        cout << "====================================" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter item to insert: ";
            cin >> item;
            list.insert(item);
            break;
        case 2:
            list.display();
            break;
        case 3:
            list.remove();
            break;
        case 4:
            quit = true;
            break;
        default:
            cout << "Invalid Selection" << endl;
            break;
        }

    } while (!quit);

    return 0;
}
