#include <iostream>
#include<queue>
using namespace std;

class Node{
public: 
    int data;
    Node*left;
    Node*right;

    Node(int value){
        this->data = value;
        this->left=NULL;
        this->right=NULL;
    }
};

Node*BSTfromINO(int arr[], int s, int e){
    if(s > e){
        return NULL;
    }

    //solving 1 case
    int mid=s+(e-s)/2;
    int element = arr[mid];
    Node*root=new Node(element);

    //Now leave everything else for recursion
    //for left part
    root->left = BSTfromINO(arr,s,mid-1);
    root->right = BSTfromINO(arr,mid+1,e);

    return root;
}
void levelOrderTraversal(Node*&root){
    if(root==NULL){
        cout << "There is Nothing to print"<< endl;
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node*frontNode=q.front();
        q.pop();

        if(frontNode==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout << frontNode->data << "->";
            if(frontNode->left!=NULL){
                q.push(frontNode->left);
            }
            if(frontNode->right!=NULL){
                q.push(frontNode->right);
            }
        }
    }
}


int main()
{
    int arr[] = {10,20,30,40,50,60,70};
    int start = 0;
    int end = (sizeof(arr)/sizeof(int))-1;

    //calling function 
    Node*rootNode = BSTfromINO(arr,start,end);
    levelOrderTraversal(rootNode);

    return 0;
}