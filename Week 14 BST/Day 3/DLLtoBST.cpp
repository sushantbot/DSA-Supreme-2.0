#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;

    //Constructor
    Node(int val){
        this->data=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};


int main()
{

    return 0;
}