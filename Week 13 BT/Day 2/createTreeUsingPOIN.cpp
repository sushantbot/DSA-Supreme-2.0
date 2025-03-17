#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

//Function for preOrderTraversal

void preOrderTraversal(Node*root){
    if(root==NULL){
        return;
    }
    //for preorder we will follow NLR
    cout << root->data << "->";
    //recursive calls for left and right subtree
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}

int SearchInorderArray(int inOrder[],int size,int element){
    //we will search element in inorder array
    for(int i=0;i<size;i++){
        if(inOrder[i]==element){
            return i;
        }
    }
}


//Create Tree using Preorder and Inorder Traversal
//remember , we need to pass "preorderIndex" by reference 
Node* createTree(int preOrder[],int inOrder[],int &preOrderIndex,int inOrderStart,int inOrderEnd,int size){
    if(preOrderIndex>=size || inOrderStart >inOrderEnd){
        return NULL;
    }
    //1 case main solve kruga baaki recursion dekh lega
    int element = preOrder[preOrderIndex];
    preOrderIndex++;
    //create node for the preorder element extracted
    Node*root = new Node(element);
    
    int position  = SearchInorderArray(inOrder,size, element);
    //from the position we will create two subtrees with the help of recursion 
    root->left=createTree(preOrder,inOrder,preOrderIndex,inOrderStart,position-1,size);
    root->right=createTree(preOrder,inOrder,preOrderIndex,position+1,inOrderEnd,size);

    //finally we will return root
    return root;
} 

int main(){
    int preOrder[]={2,8,10,6,4,12};
    int inOrder[]={10,8,6,2,4,12};
    int size = 6;
    
    int preOrderIndex= 0;
    int inOrderStart = 0;
    int inOrderEnd= 5;

    Node*rootNode = createTree(preOrder,inOrder,preOrderIndex,inOrderStart,inOrderEnd,size);

    //Now we will use traversal to check if we have done right or wrong
    preOrderTraversal(rootNode);




    return 0;
}