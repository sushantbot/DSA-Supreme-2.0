#include<iostream>
#include<vector>
using namespace std;

void Solve(int arr[],vector<int>&ans,int size,int index){
    if(index>=size){
        return; 
    }
    if(arr[index]%2==0){
        ans.push_back(arr[index]);
    }
    //Recursive call
    Solve(arr,ans,size,index+1);
} 


int main(){
    int arr[]={10,11,12,13,14,15,16,17,18,19,20};
    vector<int>ans;
    int size=sizeof(arr)/sizeof(int);
    int index=0;
    //Function Call
    Solve(arr,ans,size,index);
    //Printing Vector
    cout << " So the Answer Array is : ";
    for(auto num:ans){
        cout << num << " ";
    }


}