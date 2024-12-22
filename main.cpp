#include <iostream>
using namespace std;

// Function to distribute elements into positive, negative, and zero arrays
void distributeElements(int* arr, int size, int*& positive, int& posCount, int*& negative, int& negCount, int*& zeros, int& zeroCount)
{
    posCount = negCount = zeroCount = 0;

    // Count elements in each category
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            posCount++;
        }
        else if (arr[i] < 0)
        {
            negCount++;
        }
        else
        {
            zeroCount++;
        }
    }

    // Allocate memory for each category
    positive = new int[posCount];
    negative = new int[negCount];
    zeros = new int[zeroCount];

    // Fill arrays
    int pIndex = 0, nIndex = 0, zIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            positive[pIndex++] = arr[i];
        }
        else if (arr[i] < 0)
        {
            negative[nIndex++] = arr[i];
        }
        else
        {
            zeros[zIndex++] = arr[i];
        }
    }
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

    int* positive = nullptr;
    int* negative = nullptr;
    int* zeros = nullptr;
    int posCount, negCount, zeroCount;

    distributeElements(arr, size, positive, posCount, negative, negCount, zeros, zeroCount);

    cout << "Positive elements:\n";
    for (int i = 0; i < posCount; i++)
    {
        cout << positive[i] << " ";
    }
    cout << endl;

    cout << "Negative elements:\n";
    for (int i = 0; i < negCount; i++)
    {
        cout << negative[i] << " ";
    }
    cout << endl;

    cout << "Zero elements:\n";
    for (int i = 0; i < zeroCount; i++)
    {
        cout << zeros[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] positive;
    delete[] negative;
    delete[] zeros;

    return 0;
}
