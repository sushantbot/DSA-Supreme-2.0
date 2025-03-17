//all we have to remember in this code is that we have passed preindex by reference so that on backtracking it doesnot get restored
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << "->";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << "->";
    inOrderTraversal(root->right);
}


int findPosition(int inOrder[],int element,int size){
    for(int i=0;i<size;i++){
        if(inOrder[i]==element){
            return i;
        }
    }
    //agar nahi mile to -1 return kr do
    return -1;      //btw this is of no use b, we would surely find the position 
}

//Function declaration for creating tree
Node* createTree(int preOrder[],int inOrder[],int &preindex,int start,int end,int size){
    //Base case for recursion
    if(preindex >= size  || start > end){
        return NULL;
    }

    //first we have to define an element which will be of preOrder
    int element = preOrder[preindex];
    preindex++;     //preindex incremented so that in next recursive call we would have new element 
    
    //we have to find the index of the element in inorder array for recursive calls
    int position = findPosition(inOrder,element,size);



    //we will create a node of element
    Node*root=new Node(element);

    //Now we will call recursion for left and right subtree
    root->left = createTree(preOrder,inOrder,preindex,start,position-1,size);   //left call will be from start to position -1
    root->right = createTree(preOrder,inOrder,preindex,position+1,end,size);   //right call will be from position+1 to end

    // finally return root
    return root;
}

int main()
{
    int preOrder[] = {10, 20, 30, 50, 40, 60, 70, 80, 90};
    int inOrder[] = {50, 30, 20, 40, 10, 70, 60, 90, 80};

    int size = sizeof(inOrder)/sizeof(int);

    //parameters to pass inside the recursive function 

    int preIndex = 0;
    int start=0;
    int end = size-1;
  
    Node*rootNode = createTree(preOrder,inOrder,preIndex,start,end,size);
    //printing the preorderTraversal of the created tree to match it
    preOrderTraversal(rootNode);
    cout << endl;
    inOrderTraversal(rootNode);

}