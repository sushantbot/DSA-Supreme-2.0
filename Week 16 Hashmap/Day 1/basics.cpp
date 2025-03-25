#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int a = 90;
    // creating map
    unordered_map<string, int> mapp;

    // creating pairs in different ways to insert in mapp
    pair<string, int> p = make_pair("Sush", 20);
    pair<string, int> q("Nish", 21);
    pair<string, int> r;
    r.first = "ALok";
    r.second = 19;
    mapp["surya"] = 22;

    // Now inserting these pairs into map
    mapp.insert(p); // way 1 to insert
    mapp.insert(q); // way 1 to insert
    mapp.insert(r); // way 1 to insert

    mapp.insert(make_pair("shanky", 18));
    mapp.insert(pair<string, int>("sushi", 17));

    // Member functions of Map
    // 1.size()
    cout << "Size of Map is : " << mapp.size() << endl;

    // 2.at()
    cout << "mapping at Sush:" << mapp.at("Sush") << endl;

    // 3.count()
    cout << "count of Nish: " << mapp.count("Nisha") << endl;

    // 4.find()- can be used inside if function
    if (mapp.find("Sush") != mapp.end())
    {
        // this above line means that the Sush find iterator is not at end
        cout << "Sushh is Found" << endl;
    }
    else
    {
        // means that the iterator is at end
        cout << "Sushh is not found" << endl;
    }

    return 0;
}