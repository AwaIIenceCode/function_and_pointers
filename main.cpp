#include <iostream>
using namespace std;

// Function to allocate memory for a dynamic array
int* allocateArray(int size)
{
    return new int[size];
}

// Function to initialize a dynamic array
void initializeArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element [" << i << "]: ";
        cin >> arr[i];
    }
}

// Function to print a dynamic array
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to delete a dynamic array
void deleteArray(int* arr)
{
    delete[] arr;
}

// Function to add an element to the end of a dynamic array
void addElement(int*& arr, int& size, int element)
{
    int* temp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    temp[size] = element;
    delete[] arr;
    arr = temp;
    size++;
}

// Function to insert an element at a specific index
void insertElement(int*& arr, int& size, int index, int element)
{
    int* temp = new int[size + 1];
    for (int i = 0; i < index; i++)
    {
        temp[i] = arr[i];
    }
    temp[index] = element;
    for (int i = index; i < size; i++)
    {
        temp[i + 1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size++;
}

// Function to remove an element at a specific index
void removeElement(int*& arr, int& size, int index)
{
    int* temp = new int[size - 1];
    for (int i = 0; i < index; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++)
    {
        temp[i - 1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size--;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = allocateArray(size);
    initializeArray(arr, size);

    cout << "Initial array:\n";
    printArray(arr, size);

    int element, index;

    cout << "Enter an element to add to the end: ";
    cin >> element;
    addElement(arr, size, element);
    printArray(arr, size);

    cout << "Enter an index and element to insert: ";
    cin >> index >> element;
    insertElement(arr, size, index, element);
    printArray(arr, size);

    cout << "Enter an index to remove: ";
    cin >> index;
    removeElement(arr, size, index);
    printArray(arr, size);

    deleteArray(arr);
    return 0;
}
