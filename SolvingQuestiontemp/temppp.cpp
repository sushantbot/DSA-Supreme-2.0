#include<iostream>
#include<vector>
using namespace std;

bool checkSorted(vector<int>&arr){
    int size=arr.size();
    int index=0;
    for(int i=0;i<size-1;i++){
        if(arr[index]>arr[index+1]){
            return false;
        }
    }
    return true;
}

int main(){

    vector<int>arr={1,2,2,3,4,5};
    int ans=checkSorted(arr);
    
    if(ans==1){
        cout << "The Array is Sorted" << endl;
    }
    else{
        cout << "The array is Not sorted" << endl;
    }
}