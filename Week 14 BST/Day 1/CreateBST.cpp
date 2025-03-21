#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;

    //Constructor
    Node(int data ){
        this->data = data;
        this->left=NULL;
        this->right = NULL;
    }
};

Node*insertIntoBST(Node*&root,int data ){
    if(root==NULL){
        //this case is for the first Node
        root=new Node(data);
        return root;
    }

    //lekin agar pehle se Nodes available hain to fir recursion ke thru attach/insert krenge
    if(data > root->data){
        //then it will go to right
        root->right=insertIntoBST(root->right,data);
    }
    else{
        root->left =insertIntoBST(root->left,data);
    }

    return root;
}

void createBST(Node*&root){
    int data;
    cout << "enter data:";
    cin >> data;

    while(data!=-1){
        //we will pass this data to the function which is inserting in the BStree
        insertIntoBST(root,data);
        //again we will take input for data
        cout << "Enter Data:";
        cin >> data;
    }
}

void levelOrderTraversal(Node*&root){
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node*frontNode = q.front();
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

int main(){
    Node*root=NULL;
    createBST(root);

    cout << "Level Order Traversal\n"; 
    levelOrderTraversal(root);
    return 0;
}