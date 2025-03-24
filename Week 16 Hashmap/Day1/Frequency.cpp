#include <iostream>
#include<map>
using namespace std;

void countCharacter(map<char,int>&mapping, string str){
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        mapping[ch]++;
    }
}

int main()
{
    string str;
    cout << "Enter String :";
    getline(cin,str);

    //we will store the characters inside the map
    map<char,int>mapping;

    countCharacter(mapping,str);

    //Printing the map
    for(auto i:mapping){
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}