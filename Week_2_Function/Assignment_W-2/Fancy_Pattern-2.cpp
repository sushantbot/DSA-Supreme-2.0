#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int c=1;

    for(int row=0;row<n;row++){
        for (int col=0;col<2*row+1;col++){
            if(col%2==0){
            cout <<c;
            c++;
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
       
    }
    //  cout << "C:"<< c << endl;
    int start=c-n;
    for(int row=0;row<n;row++){
        int k=start;
        for(int col=0;col<2*n-2*row-1;col++){
            if(col%2==0){
            cout << k;
            k++;
            }
            else{
                cout << "*";
            }
            
        }
        start=start-(n-row-1);
        cout << endl;
    }
}