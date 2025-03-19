#include <iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    int data;
    cout << "enter Data:";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "for Left of Node " << data << ", ";
    root->left = createTree();

    cout << "for right of Node " << data << ", ";
    root->right = createTree();

    return root;
}

void levelOrderTraversal(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
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

void leftView1(Node*&root){
    if(root==NULL){
        return;
    }
    // if(root->left==NULL && root->right==NULL){
    //     cout << root->data << "->";
    // }
    cout << root->data << "->";

    if(root->left!=NULL){
        leftView1(root->left);
    }
    else{
        leftView1(root->right);
    }
}

void leftView(Node*&root,int level,vector<int>&arr){
    if(root==NULL){
        return;
    }
    //in normal case we will push the elements
    if(level == arr.size()){
        arr.push_back(root->data);
    }
    //then we will call left and right recursive functions
    leftView(root->left,level+1,arr);
    //we will call right on;y when we know for sure that the flow is correct
    //so that the right element of a tree which is of another level which has not been 
    //filled doesnot get added
    if(level==arr.size()){
        leftView(root->right,level+1,arr);

    }
}

int main()
{
    Node *rootNode = createTree();
    cout << "LevelOrderTraversal:\n";
    levelOrderTraversal(rootNode);
    cout << "LeftView Elements :";
    leftView1(rootNode);
    cout << "\n";

    cout << "LeftView Elements :";
    vector<int>arr;
    leftView(rootNode,0,arr);
    for(int i:arr){
        cout << i << " ";
    }
    cout << "\n";
}