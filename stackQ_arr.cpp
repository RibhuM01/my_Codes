#include <iostream>
#include "arrayHeader.h"

using namespace std;

template <typename T>
class Stack
{
private:
    array<T> arr;

public:
    void push(T item)
    {
        arr.insert(item);
    }

    void pop()
    {
        arr.remove();
    }

    void displayAll()
    {
        arr.display();
    }
};

template <typename T>
class Queue
{
private:
    array<T> arr;

public:
    void enqueue(T item)
    {
        arr.insert(item);
    }

    void dequeue()
    {
        arr.remove();
    }

    void displayAll()
    {
        arr.display();
    }
};

int main()
{
    Stack<int> stack;
    Queue<int> queue;
    int choice, item;
    bool quit = false;

    do
    {
        cout << "====================================" << endl;
        cout << "Select an option:" << endl;
        cout << "1: Use Stack" << endl;
        cout << "2: Use Queue" << endl;
        cout << "3: Exit" << endl;
        cout << "====================================" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Stack<int> stack;
            int stackOption;
            do
            {
                cout << "====================================" << endl;
                cout << "Stack Operations:" << endl;
                cout << "1: Push" << endl;
                cout << "2: Pop" << endl;
                cout << "3: Display" << endl;
                cout << "4: Back to Main Menu" << endl;
                cout << "====================================" << endl;
                cin >> stackOption;

                switch (stackOption)
                {
                case 1:
                    cout << "Enter item to push to Stack:" << endl;
                    cin >> item;
                    stack.push(item);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.displayAll();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid Selection" << endl;
                    break;
                }

            } while (stackOption != 4);
            break;
        }

        case 2:
        {
            Queue<int> queue;
            int queueOption;
            do
            {
                cout << "====================================" << endl;
                cout << "Queue Operations:" << endl;
                cout << "1: Enqueue" << endl;
                cout << "2: Dequeue" << endl;
                cout << "3: Display" << endl;
                cout << "4: Back to Main Menu" << endl;
                cout << "====================================" << endl;
                cin >> queueOption;

                switch (queueOption)
                {
                case 1:
                    cout << "Enter item to enqueue to Queue:" << endl;
                    cin >> item;
                    queue.enqueue(item);
                    break;
                case 2:
                    queue.dequeue();
                    break;
                case 3:
                    queue.displayAll();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid Selection" << endl;
                    break;
                }

            } while (queueOption != 4);
            break;
        }

        case 3:
            quit = true;
            break;

        default:
            cout << "Invalid Selection" << endl;
            break;
        }

    } while (!quit);

    return 0;
}