#include <iostream>
using namespace std;
int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }

    // int recAns = n*factorial(n-1);
    // return recAns;

    return n * factorial(n-1);
}

int main()
{
    cout << factorial(5) << endl;
    return 0;
}