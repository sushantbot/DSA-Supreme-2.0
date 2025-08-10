#include <iostream>
#include <vector>
using namespace std;

void printTargetIndex(string &str, vector<int> &ans, int index, int len, char target)
{
    if (index == len)
    {
        return;
    }

    // Processing
    if (str[index] == target)
    {
        ans.push_back(index);
    }

    // recursive call
    printTargetIndex(str, ans, index + 1, len, target);
}

int main()
{
    string str = "Sushant Kumar";
    int len = str.length();
    char target;
    cout << "Enter the target character : ";
    cin >> target;

    vector<int> ans;

    printTargetIndex(str, ans, 0, len, target);

    // printing the stored index in vector
    if (ans.size() == 0)
    {
        cout << "The target was not found in the string" << endl;
    
    }
    else
    {
        for (auto i : ans)
        {
            cout << i << " ";
        }
    }

    return 0;
}