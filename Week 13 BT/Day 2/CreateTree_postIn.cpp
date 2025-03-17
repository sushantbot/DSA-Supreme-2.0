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
        this->left = NULL;
        this->right = NULL;
    }
};

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // LRN
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << "->";
}
int SearchIn(int inOrder[],int element,int size){
    for(int i=0;i<size;i++){
        if(inOrder[i]==element){
            return i;
        }
    }
}

Node*createTree(int postOrder[],int inOrder[],int &postIndex,int start,int end,int size){
    if(postIndex < 0 || start>end){
        return NULL;
    }

    //solving one case for recursion 
    int element= postOrder[postIndex];
    postIndex--;    //Update postIndex by reference

    //Creating Node from the element
    Node*root = new Node(element);

    //Now searching that node in inorder
    int pos = SearchIn(inOrder,element,size);

    //Now here catch is that , we need to first build right subtree then left
    root->right = createTree(postOrder,inOrder,postIndex,pos+1,end,size);
    root->left = createTree(postOrder,inOrder,postIndex,start,pos-1,size);


    return root;
}



int main()
{
    int postOrder[] = {8, 6, 14, 4, 10, 2};
    int inOrder[] = {8, 14, 6, 2, 10, 4};

    int size = sizeof(postOrder) / sizeof(int);

    int postIndex = size - 1;
    int start = 0;
    int end = size - 1;

    Node *rootNode = createTree(postOrder, inOrder, postIndex, start, end, size);
    postOrderTraversal(rootNode);

    return 0;
}