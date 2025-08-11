#include <iostream>
using namespace std;

int searchB(int arr[], int size, int start, int end,int target)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start+(end-start)/2;
    // processing
    if(arr[mid]>target){
        //function call will be after the mid 
        // so start will be mid+1
        return searchB(arr,size,start,mid-1,target);
    }
    else if(arr[mid]<target){
        return searchB(arr,size,mid+1,end,target);
    }
    else{
        // this is the case where target element has been found
        return mid;
    }
}

int main()
{
    int arr[] = {20, 30, 40, 50, 60, 670, 90};
    int size = sizeof(arr) / sizeof(int);
    int index = 0;
    int target;
    cout << "Enter the Target element : ";
    cin >> target;
    if(searchB(arr,size,0,size-1,target)==-1){
        cout << "The target element was not found" << endl;
    }
    else{
        cout << "The Target element was found at index "<< searchB(arr,size,0,size-1,target) << endl;
    }
    return 0;
}