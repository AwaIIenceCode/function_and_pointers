#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isPrime(int number)
{
    if (number <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Function to remove prime numbers from a dynamic array
int* removePrimes(int* arr, int& size)
{
    int* temp = new int[size];
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (!isPrime(arr[i]))
        {
            temp[count] = arr[i];
            count++;
        }
    }

    int* newArr = new int[count];
    for (int i = 0; i < count; i++)
    {
        newArr[i] = temp[i];
    }
    delete[] temp;
    size = count;

    return newArr;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element [" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Original array:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int* newArr = removePrimes(arr, size);
    cout << "Array without prime numbers:\n";
    for (int i = 0; i < size; i++)
    {
        cout << newArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] newArr;
    return 0;
}
