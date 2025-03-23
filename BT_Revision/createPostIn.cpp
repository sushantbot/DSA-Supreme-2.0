#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;

    //Constructor
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

int SearchIninOrder(vector<int>postOrder,int targetElement,int size){
    for(int i=0;i<size;i++){
        if(postOrder[i]==targetElement){
            return i;
        }
    }
    return -1;
}

Node* createTree(vector<int>postOrder,vector<int>inOrder,int &postIndex,int start,int end,int size){
    if(postIndex < 0 || start > end){
        return NULL;
    }

    int element = postOrder[postIndex];
    postIndex--;

    //create node from element
    Node*root= new Node(element);

    int pos = SearchIninOrder(inOrder,element,size);

    //since we are traversing from right to left so we need to process right element first
    root->right = createTree(postOrder,inOrder,postIndex,pos+1,end,size);
    root->left = createTree(postOrder,inOrder,postIndex,start,pos-1,size);

    return root;
}

void levelOrderTraversal(Node*root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node*frontNode= q.front();
        q.pop();

        if(frontNode==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout << frontNode->data << " ";

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
    vector<int>postOrder = {30,40,20,60,70,50,10};
    vector<int>inOrder = {30,20,40,10,60,50,70};

    //defining some parameters to be used inside the recursive function 
    int size = postOrder.size();
    int postIndex = size-1;
    int inOrderStart=0;
    int inOrderEnd = size-1;

    Node*root = createTree(postOrder,inOrder,postIndex,inOrderStart,inOrderEnd,size);

    //printing the tree we created
    cout << "Level Order Traversal: "<< endl;
    levelOrderTraversal(root);


    return 0;
}