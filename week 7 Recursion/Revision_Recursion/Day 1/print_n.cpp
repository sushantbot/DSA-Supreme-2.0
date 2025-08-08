#include<iostream>
using namespace std;

void ascendingPrintN(int n){
    if(n==0){
        cout << n << endl;
        return;
    }
    //recursive calls
    ascendingPrintN(n-1);
    cout << n << endl;

}

void descendingPrintN(int n){
    if(n==0){
        cout << n << endl;
        return;
    }
    //recursive calls
    cout << n << endl;
    descendingPrintN(n-1);

}

int main(){
    ascendingPrintN(50);

    cout << "Printing in  descending order" << endl;
    descendingPrintN(50);
}