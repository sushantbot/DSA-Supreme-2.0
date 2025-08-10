#include <iostream>
#include <vector>
using namespace std;

vector<int> printingOccurence(int arr[], int index, int size, int target)
{
    vector<int> ans;
    if(index == size){
        return ans;
    }

    if(arr[index] == target){
        ans.push_back(index);
    }
    //getting the result from further recursive calls
    vector<int>smallAns = printingOccurence(arr,index+1,size,target);

    // merging the result of currrent call and the calls made after this recursive calls(vector.insert(position, first, last))
    ans.insert(ans.end(),smallAns.begin(),smallAns.end());
    return ans;
}

int main()
{
    int arr[] = {10, 20, 30, 30, 20, 20, 10, 20, 20, 10};
    int size = sizeof(arr)/sizeof(int);
    int target;
    cout << "Enter target Element : ";
    cin >> target;

    vector<int>ans = printingOccurence(arr,0,size,target);


    //Now printing the ans array to check if the occurence has been printed accordingly or not
    for(auto i:ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}