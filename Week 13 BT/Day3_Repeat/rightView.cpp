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



void rightView(Node*&root, int level, vector<int>&arr) {
    if (root == NULL) {
        return;
    }

    // Only push the first element encountered at this level
    if (level == arr.size()) {
        arr.push_back(root->data);
    }

    // Traverse the right subtree first, then the left subtree
    rightView(root->right, level + 1, arr);
    
    // ***Fix: Check if right subtree already filled before going left***
    // so we are calling right when there is no right at that place by checking it with 
    if (level == arr.size()) { 
        rightView(root->left, level + 1, arr);
    }
}


int main()
{
    Node *rootNode = createTree();
    cout << "LevelOrderTraversal:\n";
    levelOrderTraversal(rootNode);

    //Rightview elements function 
    cout << "Rightview Elements :";
    vector<int>arr;
    rightView(rootNode,0,arr);

    //printing the value inside the array
    for(int i:arr){
        cout << i << " ";
    }
    cout << "\n";
}