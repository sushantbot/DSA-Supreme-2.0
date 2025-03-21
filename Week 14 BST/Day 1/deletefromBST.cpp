#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node*insertNodetoBST(Node*&root,int data){
    if(root==NULL){
        //this is our first Node and we will create Root
        root=new Node(data);
        return root;
    }

    //this is the case where we need to attach the data
    if(data < root->data){
        //then we call left recursive tree
        root->left=insertNodetoBST(root->left,data);
    }
    else{
        //this is the case where data >= root->data 
        //so we will be inserting it in right subtree
        root->right=insertNodetoBST(root->right,data);
    }

    //finsally return root
    return root;
}


void createBST(Node *&root)
{
    int data;
    cout << "Enter the root Node of the BST:";
    cin >> data;

    while (data != -1)
    {
        //we will keep calling insertNodetoBST function
        insertNodetoBST(root,data);

        //now we will take input of data again
        cout << "Enter the Data :";
        cin >> data;
    }
}


//creating a function levelOrderTraversal to see the BST we created
void levelOrderTraversal(Node*&root){
    if(root==NULL){
        //there is nothing to print so return
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
            cout << frontNode->data << "->";
            //we will be pushing the childs of the frontNode if available
            if(frontNode->left!=NULL){
                q.push(frontNode->left);
            }
            if(frontNode->right!=NULL){
                q.push(frontNode->right);
            }
        }
    }
}

//we are creating a function to find the max from the BST
Node*findMax(Node*&root){
    if(root==NULL){
        return NULL;
    }

    //now we have to get to the rightest element
    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }

    //when we are out of the loop we are at the max node
    return temp;

}


//creating a function to delete the Node from BST

Node*deleteNodeBST(Node*root,int target){
    //agar kch hai hi nhi to bas root return kr do
    if(root==NULL){
        return root;
    }

    //if root==target then we have to delete 
    if(root->data == target){
        //if the root is having two nodes which is null
        if(root->left==NULL && root->right==NULL){
        //then we will just delete the node and return null because there is nothing in left and right subtree
        delete root;
        return NULL;
        }
        //one node is null and another is not null
        else if(root->left!=NULL && root->right==NULL){
            //in this case we need to store the left subtree in temp and delete the root and then return the temp
            Node*leftSubtree =root->left;
            delete root;
            return leftSubtree; 
        }
        //same case for right subtree
        else if(root->left==NULL && root->right!=NULL){
            //in this case we need to store the right subtree in temp and delete the root and then return the temp
            Node*rightSubtree =root->right;
            delete root;
            return rightSubtree; 
        }

        //this is the main case where the both left and right subtree is non null
        else{
            //first we will find the maximum from the left subtree of current root
            Node*maxi =findMax(root->left);
            //then we will replace the data of root with the maxi
            root->data = maxi->data;

            //since there is two same nodes , one replaced and another where it was taken from 
            //so we will find it and delete it and return there NULL,so recursion will do that thing for us
            // here we chose left because from here the maxi was chosen , and maxi needs to be deleted so maxi is our new target 
            root->left=deleteNodeBST(root->left,maxi->data);   
        }

    }
    
    
    //if target not found in this call then recursive calls
    else if(target < root->data){
        //then we will go in left subtree
        root->left=deleteNodeBST(root->left,target);
        
    }
    else{
        //this is the case of target > root->data, searching in right subtree
        root->right=deleteNodeBST(root->right,target);
    }
    
    return root;

}

int main()
{
    //creating tree
    Node*root=NULL;
    createBST(root);
    //printing the BST
    cout << "Level Order Traversal\n";
    levelOrderTraversal(root);
    cout << endl;


    //now deleting the Node
    int target;
    cout << "enter the target Eement";
    cin >> target;

    while(target!=-1){
        root=deleteNodeBST(root,target);
        levelOrderTraversal(root);  //printing after deletion
        //now again take target as input
        //when you want to stop, just take -1 as input
        cout << "enter target ";
        cin >> target;
    }


}