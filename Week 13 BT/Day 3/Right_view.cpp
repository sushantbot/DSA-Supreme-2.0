#include<iostream>
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

Node* createTree(){
    int data;
    cout << "Enter the data for Node:";
    cin >> data;

    if(data==-1){
        return NULL;
    }

    Node*root=new Node(data);

    cout << "For left of Node:"<< data << ", ";
    root->left=createTree();
    cout << "For right of Node:"<< data << ", ";
    root->right=createTree();


    return root;
}



void levelOrderTraversal(Node*&root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    //we wil lrun while loop till the queue is not empty
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


void right_view(Node*root,vector<int>&vect,int level){
    if(root==NULL){
        return;
    }
    if(level==vect.size()){
        //in this case we will push the elemnt into array
        vect.push_back(root->data);
    }

    //now recursive calls
    right_view(root->right,vect,level+1);
    right_view(root->left,vect,level+1);
}


int main(){
    //creating tree
    Node*rootNode=createTree();

    //Now passing this node in level order traversal
    levelOrderTraversal(rootNode);

    //calling function to print the rightView
    vector<int>brr;
    int right_level=0;
    right_view(rootNode,brr,right_level);

    //Now our brr array is created 
    cout << "Right View array is : ";
    for(int i:brr){
        cout << i << ",";
    }
    cout << endl;
}