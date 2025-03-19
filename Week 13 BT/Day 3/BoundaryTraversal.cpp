#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // constructor'
    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    int data;
    cout << "Enter the datas for Node:";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "For left of Node " << data << ", ";
    root->left = createTree();
    cout << "For right of NOde " << data << ", ";
    root->right = createTree();

    return root;
}

void levelOrderTraversal(Node*&root){
    queue<Node*>q;

    //initial push
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node*frontElement=q.front();
        q.pop();

        if(frontElement==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout << frontElement->data << " ";
            if(frontElement->left!=NULL){
                q.push(frontElement->left);
            }
            if(frontElement->right!=NULL){
                q.push(frontElement->right);
            }
        }
    }
}


void printLeftBoundary(Node*&root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    cout << root->data << "->";
    //there will be if case for recursive call 
    if(root->left!=NULL){
        printLeftBoundary(root->left);
    }
    else{
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(Node*&root){
    if(root==NULL){
        return; 
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }

    //we will be printing the right boundary on backtracking
    //so that the order or printing is reversed

    //so first we will do recursive call 
    if(root->right!=NULL){
        printRightBoundary(root->right);
    }
    else{
        printRightBoundary(root->left);
    }

    //then printing
    cout << root->data << "->";

}
void printleafBoundary(Node*root){
    if(root==NULL){
        return;
    }
    //we will printthe leaf node
    if(root->left==NULL && root->right==NULL){
        cout << root->data << "->";
    }

    //recrusive calls
    printleafBoundary(root->left);
    printleafBoundary(root->right);
}

void boundaryTraversalCombined(Node*root){
    if(root==NULL){
        return;
    }
    // printLeftBoundary(root);
    // printleafBoundary(root);
    // if(root->right!=nullptr){
    //     printRightBoundary(root->right);
    // }
    // else{
    // printRightBoundary(root->left);

    //we can replace code of line 127 to 133 by 
    cout << root->data << "->";
    printLeftBoundary(root->left);
    printleafBoundary(root);
    printRightBoundary(root->right);

}


int main()
{
    Node*rootNode=createTree();
    cout << "Level Order Traversal: \n";
    levelOrderTraversal(rootNode);
    boundaryTraversalCombined(rootNode);
    return 0;
}

//there is flaw in  this code when used testcase
// 10 -1 30 50 70 110 -1 -1 111 -1 -1 80 -1 -1 60 -1 90 112 -1 -1 113 -1 -1

// correct output with this
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 