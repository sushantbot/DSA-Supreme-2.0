#include<iostream>
using namespace std;

int PrintSum(int arr[3][4],int row,int col){
    for(int i=0;i<col;i++){
        int sum=0;
        for(int j=0;j<row;j++){
            sum=sum+arr[j][i];
        }
        cout << sum << endl;
    }
}

int PrintArray(int arr[][4],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr[][4]={

        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20},

    };

    int row=5;
    int col=4;

    PrintArray(arr,row,col);
    PrintSum(arr,row,col);

}