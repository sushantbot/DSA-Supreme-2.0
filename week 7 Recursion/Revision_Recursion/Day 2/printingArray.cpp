#include <iostream>
using namespace std;

void printArray(int arr[], int index, int size)
{

    if (index == size)
    {
        return;
    }
    printArray(arr, index + 1, size);
    cout << arr[index] << " ";
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, 0, size);
    return 0;
}