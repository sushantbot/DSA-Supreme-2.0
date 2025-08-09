#include <iostream>
using namespace std;

int searchinArray(int arr[],int index,int target,int size){
    if(index == size){
        return -1;
    }

    //checking if the element is found in the array or not
    if(arr[index]==target){
        return index;
    }

    //now recursive answer
    return searchinArray(arr,index+1,target,size);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(arr) / sizeof(int);
    int target;
    cout << "Enter target Element :"; 
    cin >> target;

    int ans = searchinArray(arr, 0, target,size);
    if(ans == -1){
        cout << "The target Element was not found" << endl;
    }
    else{
        cout << "The Target element was found at index "<< ans << endl;
    }
    return 0;
}