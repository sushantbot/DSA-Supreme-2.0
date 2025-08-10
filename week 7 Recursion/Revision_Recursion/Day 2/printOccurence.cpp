#include <iostream>
#include <vector>
using namespace std;

void printingOccurence(int arr[], vector<int> &ans, int index, int size, int target)
{
    if(index==size){
        return;
    }

    if(arr[index] == target){
        ans.push_back(index);
    }

    printingOccurence(arr,ans,index+1,size,target);
}

int main()
{
    int arr[] = {10, 20, 30, 30, 20, 20, 10, 20, 20, 10};
    int size = sizeof(arr)/sizeof(int);
    int target;
    cout << "Enter target Element : ";
    cin >> target;

    vector<int>ans; 
    printingOccurence(arr,ans,0,size,target);


    //Now printing the ans array to check if the occurence has been printed accordingly or not
    for(auto i:ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}