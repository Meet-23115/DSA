#include <iostream>
using namespace std;

class arra
{
private:
    int *arr;     // Pointer to dynamically allocated array
    int capacity; // Maximum size of the array
    int size;

public:
    arra(int cap) : capacity(cap), size(0)
    {
        arr = new int[capacity]; // Allocate memory for the array
    }

    void add(int x)
    {
        if (size < capacity)
        {
            arr[size++] = x;
        }
        else
        {
            cout << "Array is full. Cannot add more elements." << endl;
        }
    }

    // Access an element by index
    int get(int index) const
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        else
        {
            cout << "Index out of bounds!" << endl;
            return -1; // Return an invalid value for error
        }
    }

    // Display the array contents
    void display() const
    {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~arra()
    {
        delete[] arr; // Free allocated memory
    }
};

int main()
{

    arra arr(5);

    arr.add(1);
    arr.add(2);
    arr.add(3);
    arr.add(4);
    arr.add(5);
    arr.display();
    cout << arr.get(2);

    arr.add(1);

    return 0;
}