#include <iostream>
#include <queue>
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
Node *insertIntoBST(Node *&root, int data)
{
    if (root == NULL)
    {
        // if there dne any tree then we create one first
        root = new Node(data);
        // then return
        return root;
    }
    // but if there exist tree, then we need to insert the data node to correct place
    if (root->data > data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // if  data > root->data
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}
void createBST(Node *&root)
{
    int data;
    cout << "Enter the Root Of BST :";
    cin >> data;

    while (data != -1)
    {
        // calling inserting function
        insertIntoBST(root, data);

        // again taking input of data
        cout << "Enter data :";
        cin >> data;
    }
}

void levelOrderTraversal(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
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

            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }
    }
}

bool searchTarget(Node *&root, int target)
{
    if (root == NULL)
    {
        return false;
    }

    // Now solving One case
    if (root->data == target)
    {
        return true;
    }

    //recursive calls
    int leftAns= false;
    int rightAns= false;

    if(target < root->data){
        // then we will search in left Subtree
        leftAns=searchTarget(root->left,target);
    }else{
        // target>root->data so we will find in right subtree
        rightAns=searchTarget(root->right,target);
    }

    //now finally we will return the "or" value of left and right
    return leftAns || rightAns;
}

int main()
{
    Node *rootNode = nullptr;
    createBST(rootNode);

    // Now we will print the BST by level order tarversal
    cout << "Level Order Traversal :\n";
    levelOrderTraversal(rootNode);

    cout << "Enter the Target Element:";
    int target;
    cin >> target;

    // search function called
    while(target!=-1){
        if (searchTarget(rootNode, target))
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "not found" << endl;
        }
        cout << "Enter target Element:";
        cin >> target;
    }
}


// 50 30 60 25 40 70 80 55 -1