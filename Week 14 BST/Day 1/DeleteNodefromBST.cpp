#include <iostream>
#include<queue>
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

Node*insertIntoBST(Node*&root,int data){
    //if it is our first call then we need to create root
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    //now if it is not first node/ rootNode, then we need to attach it
    
    // if the data > root->data, then right recursive call
    if(data < root->data){
        root->left=insertIntoBST(root->left,data);
    }
    // if the data >= root->data, then right recursive call
    else{
        root->right=insertIntoBST(root->right,data);
    }

    //now return root
    return root;

}

void createBST(Node*&root){
    int data;
    cout << "Enter the rootNode of BST:";
    cin >> data;

    while(data!=-1){
        //pass into insert function 
        insertIntoBST(root,data);

        //Now we will take input of new data
        cout << "Enter the Data :";
        cin >> data ;
    }
}

void levelOrderTraversal(Node*&root){
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
            cout << frontNode->data << "->";
            if(frontNode->left!=NULL){
                q.push(frontNode->left);
            }
            if(frontNode->right!=nullptr){
                q.push(frontNode->right);
            }
        }
    }
}

Node*findMax(Node*&root){
    if(root==NULL){
        return NULL;
    }

    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    //finally return it
    return temp;
}

Node*deleteNodefromBST(Node*root,int target){
    if(root==NULL){
        // then nothing to do
        return nullptr;
    }

    //if the target has been found
    if(root->data == target){
        //there is four cases which need to be taken care of
        
        if(root->left==NULL && root->right==NULL){
            // case-1 when the node is a leaf node(just delete the node and return null)
            delete root;
            return NULL;
        }
        
        else if(root->left==NULL && root->right!=NULL){
            //case-2 when left is null but right is not null;
            //store the non null in temporary node and then delete and finally return it
            Node*temp=root->right;
            delete root;
            
            return temp;    //this will get attached at the node which is deleted
        }

        else if(root->left!=NULL && root->right==NULL){
            //case-3 when left is null but right is not null;
            //store the non null in temporary node and then delete and finally return it
            Node*temp=root->left;
            delete root;
            
            return temp;    //this will get attached at the node which is deleted
        }
        else{
            //this 4th case is the main case
            //when both the lft and right of node is not null
            //first we need to find the max of this subtreee in left and then replace the data of root node with max 
            //then return root
            //an then find the maxi in subtree and delete it

            Node* maxi=findMax(root->left);
            root->data =maxi->data;
            //find maxi in root->left
            root->left=deleteNodefromBST(root->left,maxi->data);
            return root;

        }

    }
    //but agar hme target hi nhi mila abhi tk to 
    //recursive calls krenge left aur right ke liye

    else if(target < root->data){
        //then we need to search the target in left subtree
        root->left=deleteNodefromBST(root->left,target);
    }
    else{
        //in this case we need to search the target in right subtree
        root->right=deleteNodefromBST(root->right,target);
    }

    //then finally return root when everything has been done
    return root;
}



int main()
{
    Node*rootNode=NULL;
    createBST(rootNode);

    //PrintBST
    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(rootNode);

    rootNode= deleteNodefromBST(rootNode,35);
    cout << endl;
    levelOrderTraversal(rootNode);
    
}

//a testcase to check when revising
//10 20 5 21 17 9 4 2 54 56 53 67 9 -1

//20 15 30 8 18 25 35 4 9 16 19 32 45 5 11 31 34 -1