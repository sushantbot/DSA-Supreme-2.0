#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Now we will be crreating tree
Node *createTree()
{
    int data;
    cout << "Enter the data for Node:";
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }

    Node *root = new Node(data);

    cout << "for left of Node " << data << ", ";
    root->left = createTree();

    cout << "for right of Node " << data << ", ";
    root->right = createTree();

    return root;
}

// Now we will be creating level order traversal
void levelOrderTraversal(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == nullptr)
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
            if (frontNode->left != nullptr)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right != nullptr)
            {
                q.push(frontNode->right);
            }
        }
    }
}

void top_view(Node*&root){
    //we will create a map for sotring node_data to hd key value pairs
    map<int,int>hdtoNode;


    //Now we will create a queue in which each element will consist of pairs
    queue<pair<Node*,int> >q;
    //         Node , hd
    
    //now pusing the initial state like lot
    q.push(make_pair(root,0));

    while(!q.empty()){
        //now we will extract the front pair of the queue
        pair<Node*,int>temp=q.front();
        q.pop();     //we will pop to make make sure loop runs smoothly

        Node*frontNode= temp.first;
        int hd = temp.second;

        //if there is no entry for hd in map,then we will create a new one
        if(hdtoNode.find(hd)==hdtoNode.end()){
            hdtoNode[hd]=frontNode->data;
        }

        //now we will be pushing the childs of the current frontNode inside the queue
        if(frontNode->left!=NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right!=NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    //since our map has been filled properly 
    //Now we will print the Nodes data of map which is our top view
    for(auto i:hdtoNode){
        cout << i.second << " ";//key is our first and value is second here first is hd and second is node->data
    }
    cout << endl;

}

int main()
{
    Node*rootNode=createTree();
    
    levelOrderTraversal(rootNode);
    cout << "\n";

    //Now we will be printing thetop view
    cout << "Top View is : ";
    top_view(rootNode);

}