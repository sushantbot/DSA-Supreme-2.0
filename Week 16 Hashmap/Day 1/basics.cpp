#include<iostream>
#include<unordered_map>
using namespace std;


int main() {
    unordered_map<string,int>mapping;

    //inserting the element in map
    pair<string,int>p = make_pair("Sushant",21);
    pair<string,int>q("Sushantt",24);
    pair<string,int>r;
    r.first ="Arun";
    r.second = 23;

    //ways of inserting the key value pairs in map
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    mapping["Nishant"] = 23;


    cout << "Size of map is :" << mapping.size() << endl;

    // Accessing the valuee

    cout << mapping.at("Sushant") << endl;
    cout << mapping["Sushantt"]  << endl;
    cout << mapping["Nishant"]  << endl;

    // count() function prints 1 if that key is present in the map otherwise 0 
    cout << mapping.count("Sushantt") << endl;

    // find() function : it is iterator which gets to the end if the key is not found 
    if(mapping.find("Sushantt") != mapping.end()){  // agar end pe hota to iska mtlbb wo mila hi nhi 
        cout << "Found" << endl;
    }
    else {
        cout << "Not found" << endl;
    }



}