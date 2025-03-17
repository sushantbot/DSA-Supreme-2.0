#include <iostream>
#include<queue>
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

Node*createTree(){
    int data;
    cout << "Enter Data : ";
    cin >> data;
    if(data==-1){
        return NULL;
    }

    //if data is not null we will create node with data
    Node*root= new Node(data);
    //Now we will be attaching left and right subtree
    cout << "For left of Node "<< root->data << ", ";
    root->left=createTree();
    cout << "For right of Node "<< root->data << ", ";
    root->right=createTree();

    return root;

}

//Now we will be creating a function for level order Traversal
void LevelOrderTraversal(Node*root){
    // if(root==NULL){
    //     return;
    // }
    queue<Node*>q;
    //Iitial pushing of elements
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();         //pop the element
        if(frontNode==nullptr){
            //in this case we will be adding new line
            cout << endl;
            //Now check if the queue is empty, otherwise push nullptr
            if(!q.empty()){
                q.push(nullptr);
            } 
        }
        else{
            //we will be printing the elements and pushing the child of this node to the queue
            cout << frontNode->data << "->";
            if(frontNode->left!=NULL){
                q.push(frontNode->left);
            }
            if (frontNode->right!=NULL){
                q.push(frontNode->right);
            }
        }
    }
}

void left_view(Node*root,int level,vector<int>&arr){
    //catch is the level , we will push the data of node iff level==size of the array
    //which means that the for each level there should be only one element
    //so we will push it when we know that the size = level
    if(root==NULL){
        return;
    }

    //1 case khud solve krenge
    if(level==arr.size()){
        //agar size of array aur level same hua tabhi hi push krenge elements
        arr.push_back(root->data);
    }

    //baaki recursive call sambhal lega
    left_view(root->left,level+1,arr);
    left_view(root->right,level+1,arr);

}

int main()
{
    Node*rootNode= createTree();

    cout << "Level Order Traversal\n";
    LevelOrderTraversal(rootNode);


    //Creating array for storing the node data of left
    vector<int>arr;
    //Now our objective is to print an array of elements consisting 10,20,30
    left_view(rootNode,0,arr);

    //Now we will be printing the arr to check what is stored and cross verify
    cout << "The Left View Elements are:";
    for(int i:arr){
        cout << i << "->";
    }
    cout << endl;
    
    return 0;
}