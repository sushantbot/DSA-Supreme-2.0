#include <iostream>
#include<vector>
using namespace std;

vector<int> conversiontoVectr(int num){
    vector<int> ans;
    if(num < 10){
        ans.push_back(num);
        return ans;
    }

    // now doing the basic math ( processing )
    int digit = num % 10;
    num = num/10;
    
    // recursive call
    vector<int>smallAns = conversiontoVectr(num);
    // so that it gets stored left to right
    ans.insert(ans.end(),smallAns.begin(),smallAns.end());
    ans.push_back(digit);
    return ans;


}


int main()
{   
    int num ;
    cout << "Enter the number : ";
    cin >> num;
    //now our job is to store the digits of this number in vector using recursion
    vector<int>ans = conversiontoVectr(num);
    // printting the vector
    for(auto i:ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}