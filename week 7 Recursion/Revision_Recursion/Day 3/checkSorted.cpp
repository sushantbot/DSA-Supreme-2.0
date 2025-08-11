#include <iostream>
using namespace std;

bool checkSorted(int arr[],int size,int index){
    if(index>=size){
        return true;
    }

    // checking the current case
    if(arr[index] >= arr[index-1]){
        bool recAns = checkSorted(arr,size,index+1);
        return recAns;
    }
    else{
        return false;
    }
}

int main()
{
    int arr[]= {10,20,30,50,30,10,90};
    // int arr[]= {10,20,20,30,40,50,60};
    int size = sizeof(arr)/sizeof(int);
    int index = 1;



    // checkSorted(arr,index,size) ? cout << "The array is Sorted" << endl : cout << "The array is not sorted";
    if(checkSorted(arr,size,index)){
        cout << "The Array is Sorted"<< endl;
    }
    else{
        cout << "The Array is not sorted"<< endl;
    }
    return 0;
}