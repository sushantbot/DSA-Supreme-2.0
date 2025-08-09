#include <iostream>
#include<limits.h>
using namespace std;

int findMax(int arr[],int index,int size){
    if(index == size-1){
        return arr[index];
    }

    //now returning the max from the recursive call and current element
    return max(arr[index],findMax(arr,index+1,size));
}

// int findMax(int arr[],int index,int size,int &max){
//     if(index==size){
//         return max;
//     }

//     if(arr[index]>max){
//         max= arr[index];
//     }
//     //recursiveCall
//     return findMax(arr,index+1,size,max);
// }

int findMin(int arr[],int index,int size,int &min){
    if(index == size){
        return min;
    }

    if(arr[index]<min){
        min = arr[index];
    }
    
    return findMin(arr,index+1,size,min);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(arr) / sizeof(int);
    int target;
    int max = INT_MIN;
    // cout << " The max in the Array is : " << findMax(arr,0,size,max) << endl;
    cout << " The max in the Array is : " << findMax(arr,0,size) << endl;



    int min = INT_MAX;
    cout << " The min in the Array is : " << findMin(arr,0,size,min);
    return 0;
}