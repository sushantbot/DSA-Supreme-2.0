#include <iostream>
#include<vector>
using namespace std;

void conversiontoVectr(vector<int>&ans,int num){
    if(num == 0 ){
        return;
    }

    // now doing the basic math ( processing )
    int digit = num % 10;
    num = num/10;
    
    // recursive call
    conversiontoVectr(ans,num);
    // so that it gets stored left to right
    ans.push_back(digit);


}


int main()
{   
    int num ;
    cout << "Enter the number : ";
    cin >> num;
    //now our job is to store the digits of this number in vector using recursion
    vector<int>ans;
    conversiontoVectr(ans,num);
    // printting the vector
    for(auto i:ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}