#include <iostream>
using namespace std;

int powerN(int n){
    if(n==0){
        return 1;
    }

    int recAns = 2 * powerN(n-1);
    return recAns;
}

int main()
{   
    cout << powerN(10) << endl;

    return 0;
}