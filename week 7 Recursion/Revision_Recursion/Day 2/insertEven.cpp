#include <iostream>
#include<vector>
using namespace std;

void insertEven(vector<int>&arr,vector<int>&ans,int index,int size){
    if(index==size){
        return;
    }

    if(arr[index]%2==0){
        ans.push_back(arr[index]);
    }

    //recursive call
    insertEven(arr,ans,index+1,size);
}


int main()
{   
    vector<int>ans;
    vector<int>arr = {1,2,4,5,6,8,0,12};

    insertEven(arr,ans,0,arr.size());
    for(auto i:ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}