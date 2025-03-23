#include <iostream>
#include<vector>
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

void left_View(Node*root,int level,vector<int>&arr){
    //base case when to stop
    if(root==NULL){
        return;
    }

    //we will push the elements into the array when we have the level = arr.size
    if(arr.size() == level){
        arr.push_back(root->data);
    }

    //left and right recursive calls
    left_View(root->left,level+1,arr);
    left_View(root->right,level+1,arr);

}
     

void right_view(Node*&root,int level,vector<int>&brr){
    if(root==NULL){
        return;
    }

    //if the level == arr.size(), then we will push it to the array
    if(brr.size()==level){
        brr.push_back(root->data);
    }

    //Since we are interested in right view , we will call right first
    right_view(root->right,level+1,brr);
    right_view(root->left,level+1,brr);
}






int main()
{
    Node*rootNode = createTree();
    levelOrderTraversal(rootNode);


    int level = 0;

    //part of left Value
    vector<int>arr;
    left_View(rootNode,level,arr);
    cout << "Left_View is :";
    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;

    //part of rightValue
    vector<int>brr;
    right_view(rootNode,level,brr);
    cout << "Right View is :";
    for(auto i:brr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}