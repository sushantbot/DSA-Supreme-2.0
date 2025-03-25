#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> mapp = {
        {"Sushant", 43},
        {"Nishant", 84},
        {"Alok", 64}};

    // printing the size of map which is 3
    cout << "Size of Map is :" << mapp.size() << endl;

    //Accessing the value of the map
    cout << "mapp[""Sushant""]:" << mapp["Sushant"]<< endl;

    //using find function
    if(mapp.find("Sushant")!=mapp.end()){
        cout << "The key Sushant is found" << endl;
    }
    else{
        cout << "The key Sushant is not found" << endl;
    }

    //we can say find function is relational operator which is used to compare and returns 1 in case of true
    cout << (mapp.find("Sushant")!=mapp.end()) << endl;

    return 0;
}