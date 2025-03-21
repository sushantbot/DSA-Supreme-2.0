#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node*insertIntoBST(Node*&root,int data){
    if(root==NULL){
        //this is the first node of the BST
        root=new Node(data);
        return root;
    }

    //if this is not the first node of the BST, then we will be connecting the nodes at appropriate places
    if(root->data > data){
        root->left =  insertIntoBST(root->left,data);
    }
    else{
        // (root->data < data)
        root->right =  insertIntoBST(root->right,data);
    }

    return root;
}

void createBst(Node*&root){
    int data;
    cout << "Enter Data: ";
    cin >> data;

    while(data!=-1){
        insertIntoBST(root,data);
        //again taking input 
        cout << "Enter Data: ";
        cin >> data;
    }
}


void levelOrderTraversal(Node*&root){
    if(root==NULL){
        return;
    }

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





int main()
{
    Node*root=NULL;
    createBst(root);
    //levelordertraversal
    levelOrderTraversal(root);
}