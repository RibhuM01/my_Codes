#include <iostream>
using namespace std;

class DynamicArray {
private:
    int *arr;
    int capacity;
    int size;

public:
    DynamicArray(int initialCapacity = 2) {
        capacity = initialCapacity;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void insertBack(int value) {
        if (size == capacity) {
            capacity *= 2;
            int *newArr = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size++] = value;
    }

    void removeBack() {
        if (size > 0) {
            int deletedValue = arr[size - 1];
            --size;
            if (size <= capacity / 2) {
                capacity /= 2;
                int *newArr = new int[capacity];
                for (int i = 0; i < size; ++i) {
                    newArr[i] = arr[i];
                }
                delete[] arr;
                arr = newArr;
            }
            cout << "Deleted element: " << deletedValue << endl;
        } else {
            cout << "Array is empty. Cannot delete." << endl;
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;

    int choice, value;

    do {
        cout << "1. Insert at end\n";
        cout << "2. Delete from end\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                arr.insertBack(value);
                break;
            case 2:
                arr.removeBack();
                break;
            case 3:
                cout << "Array: ";
                arr.display();
                break;
            case 4:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}