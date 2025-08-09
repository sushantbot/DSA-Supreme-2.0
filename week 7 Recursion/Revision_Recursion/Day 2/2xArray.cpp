#include <iostream>
#include<vector>
using namespace std;

void mulVctor(vector<int>&arr,int index,int size){
    if(index==size){
        return;
    }   

    //now multiplying the elements inside the vector with 2

    arr[index]*=2;

    //recrusive call
    mulVctor(arr,index+1,size);


}


int main()
{
    vector<int>arr = {10,20,30,40,50,60,70};
    int size = arr.size();

    // calling function 

    mulVctor(arr,0,size);


    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}