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

int search(vector<int>inOrder,int target){  
    for(int i=0;i<inOrder.size();i++){
        if(inOrder[i]==target){
            return i;
        }
    }
}

Node*createTree(vector<int>preOrder,vector<int>inOrder,int &preIndex,int inOrderStart,int inOrderEnd,int size){
    if(preIndex>=size ||inOrderStart > inOrderEnd){
        return NULL;
    }

    int element = preOrder[preIndex];
    preIndex++;

    //creating root Node with the element
    Node*root=new Node(element);

    //Now searching element in inOrder
    int position = search(inOrder,element);

    //since we have got the target index , so out recursive call will be divided in two segment
    root->left = createTree(preOrder,inOrder,preIndex,inOrderStart,position-1,size);
    root->right = createTree(preOrder,inOrder,preIndex,position+1,inOrderEnd,size);

    return root;


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
    vector<int>preOrder={10,20,30,40,50,60,70};
    vector<int>inOrder={30,20,40,10,60,50,70};

    int preIndex = 0;
    int inOrderStart = 0;
    int size = inOrder.size();
    int inOrderEnd = inOrder.size()-1;
    Node*root=createTree(preOrder,inOrder,preIndex,inOrderStart,inOrderEnd,size);

    // Now we will be printing the tree
    //using levelOrderTraversal
    cout << "Level Order Traversal\n";
    levelOrderTraversal(root);

    return 0;
}