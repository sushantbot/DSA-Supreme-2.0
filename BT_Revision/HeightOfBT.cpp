#include <iostream>
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


Node* createTree(){
    cout << "Enter Data for the Node:";
    int data;
    cin >> data ;

    if(data==-1){
        return NULL; 
    }

    Node*root = new Node(data);
    cout << "for Left of Node :"<< data << ", ";
    root->left = createTree();
    cout << "for right of Node :"<< data << ", ";
    root->right=createTree();

    return root;
}   

void preOrderTraversal(Node*&root){
    if(root==NULL){
        return;
    }

    cout << root->data << "->";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrdertraversal(Node*&root){
    if(root==NULL){
        return;
    }

    inOrdertraversal(root->left);
    cout << root->data << "->";
    inOrdertraversal(root->right);
}
void postOrderTraversal(Node*&root){
    if(root==NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << "->";
}

void levelOrderTraversal(Node*root){
    if(root==NULL){
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
            //if the frontNode is not null then print and push its child
            cout << frontNode->data<< "->";
            if(frontNode->left!=NULL){
                q.push(frontNode->left);
            }
            if(frontNode->right!=NULL){
                q.push(frontNode->right);
            }
        }
    }
}

//function to define the height of the tree
int height(Node*&root){
    if(root==NULL){
        return 0;
    }

    int leftSubtree = height(root->left);
    int rightSubtree = height(root->right);

    //operation on recursive calls
    return max(leftSubtree,rightSubtree)+1; 
}

int main()
{
    Node*rootNode=createTree();
    // cout << "Printing PreOrder Traversal: ";
    // preOrderTraversal(rootNode);
    // cout << endl;
    // cout << "Printing InOrder Traversal: ";
    // inOrdertraversal(rootNode);
    // cout << endl;
    // cout << "Printing PostOrder Traversal: ";
    // postOrderTraversal(rootNode);
    // cout << endl;

    // cout << "printing LevelOrderTraversal:\n";
    // levelOrderTraversal(rootNode);  //working fine till here

    
    // //checkpoint1
    cout << "The height of the Tree is :"<< height(rootNode) << "\n";

    return 0;
}


//testCase for checking
// 10 20 30 -1 -1 40 -1 -1 50 60 -1 -1 70 -1 -1