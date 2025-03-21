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
    if(root==NULL){
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

int findMin(Node *&root)
{
    if (root == NULL)
    {
        // in this case we need to send -1
        return -1;
    }
    // we will run while loop untill we get our min
    Node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }

    // now our temp is out min element
    return temp->data;
}

int findMax(Node *&root)
{
    if (root == NULL)
    {
        // in this case we need to send -1
        return -1;
    }
    // we will run while loop untill we get our min
    Node *temp = root;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }

    // now our temp is out min element
    return temp->data;
}

int main()
{
    Node *rootNode = nullptr;
    createBST(rootNode);

    // Now we will print the BST by level order tarversal
    cout << "Level Order Traversal :\n";
    levelOrderTraversal(rootNode);

    cout << "Maximum is :" << findMax(rootNode) << ", and Minimum is :" << findMin(rootNode) << endl;
}