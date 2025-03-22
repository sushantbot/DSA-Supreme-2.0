#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node*insertIntoBST(Node*&root,int data){
    if(root==NULL){
        //this is the first node of the BST
        root=new Node(data);
        return root;
    }

    //if this is not the first node of the BST, then we will be connecting the nodes at appropriate places
    if(root->data > data){
        root->left =  insertIntoBST(root->left,data);
    }
    else{
        // (root->data < data)
        root->right =  insertIntoBST(root->right,data);
    }

    return root;
}

void createBst(Node*&root){
    int data;
    cout << "Enter Data: ";
    cin >> data;

    while(data!=-1){
        insertIntoBST(root,data);
        //again taking input 
        cout << "Enter Data: ";
        cin >> data;
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
        Node*frontNode = q.front();
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

Node* findMin(Node*&root){
    // but the is not possible because we will be executing the 4th case iff both the nodes are valid
    // if(root==NULL){
    //     return NULL;
    // }
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    //since we are on the min Node
    //just return it
    return temp;
}

Node*deleteNodefromBST(Node*root,int target){
    if(root==NULL){
        return NULL;
    }

    //if we get target
    if(root->data == target){
        //in this case there are 4 cases
        // case 1  jab root ka dono side koi node nahi ho
        if(root->left==NULL && root->right==NULL){
            //in this case we will just delete the node and return nullptr
            delete root;
            return nullptr;
        }
        else if(root->left==NULL && root->right!=NULL){
            //in this case we will store the not null part in temp and delete the target and return the sotred part
            Node*temp = root->right;
            delete root;
            return temp;
        }
        //similar to above case
        else if(root->left!=nullptr && root->right==nullptr){
            //in this case we will store the non null part and delete the target which is root and return the stored node/tre
            Node*temp=root->left;
            delete root;
            return temp;
        }
        //most important case when both the left and right is non null
        //then in that case we will just find the max from the leftsubtree or min from the rightSubtree
        else{
            //we will find the min from right
            Node* mini = findMin(root->right);
            //now we will replace the 
            root->data = mini->data;
            //now we will search for mini as target in the root->right so that it doesnot occur twice in BST
            root->right = deleteNodefromBST(root->right,mini->data);
            return root;
        }

    }

    //if we dont find target we will use recurssion 
    else if(root->data < target){
        //then we will go into the right subtree
        root->right =deleteNodefromBST(root->right,target); 
    } 
    else{
        root->left=deleteNodefromBST(root->left,target); 
    }

    // finally return root
    return root;
}

//creating a function to convert tree into Doubly Linked List using left and right pointer as it is

void ConvertDLL(Node* root,Node*&head){
    if(root==NULL){
        return;
    }

    //we will follow RNL so that head comes to our first node in sorted 
    //processing R
    ConvertDLL(root->right,head);

    //process the current Node
    root->right = head;
    if(head!=NULL){
        head->left = root;
    }
    head=root;

    //processing L
    ConvertDLL(root->left,head);
}

void printLL(Node*&head){
    Node*temp=head;
    if(temp==NULL){
        return;
    }

    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->right;   //here right is there in place of next
    }
}



int main()
{
    Node*root=NULL;
    createBst(root);
    //levelordertraversal
    levelOrderTraversal(root);


    int target;
    cout << "enter the Node you wish to delete : ";
    cin >> target;
    while(target!=-1){
        root=deleteNodefromBST(root,target);
        levelOrderTraversal(root);
        //again take input for target
        cout << "Enter Target: ";
        cin >> target;
    }

    Node*head = NULL;
    ConvertDLL(root,head);
    //now we will call convert tree function 
    printLL(head);
}