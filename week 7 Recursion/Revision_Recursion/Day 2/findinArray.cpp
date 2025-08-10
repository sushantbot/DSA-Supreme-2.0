#include <iostream>
using namespace std;

int findinArr(int arr[], int index, int size, int target)
{
    if (index == size){
        return -1;
    }

    if(arr[index]==target){
        return index;
    }

    int recAns = findinArr(arr,index+1,size,target);
    return recAns;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int target;
    cout << "enter Target element :";
    cin >> target;
    int size = sizeof(arr) / sizeof(int);

    if (findinArr(arr, 0, size, target) == -1)
    {
        cout << "The Target ELement was not found" << endl;
    }
    else
    {
        cout << "The target element was found in array at index : "<< findinArr(arr,0,size,target) << endl;
    }
    return 0;
}