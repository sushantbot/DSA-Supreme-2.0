#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    //Ctor
    Node(int value){
        this->data = value;
        this->left=NULL;
        this->right = NULL;
    }
};

void insertIntoBST(Node*&root,int data){
    //since we are given data, we will insert in left and right if therre is node availble
    //if not we will create root Node
    if(root==NULL){
        root=new Node(data);
        return;
    }

    //but if the root NOde is already there then we will attach it in the Tree using recursion 
    if(data < root->data){
        //then we will attach the node in left SubTree
        insertIntoBST(root->left,data);
        //this will just go in till it finds the node which is null and will just create new Node and return and the function call ends
    }
    else{
        // if data >root->data , then  we will attach in right subtree
        insertIntoBST(root->right,data);
    }

    //we dont need to return anything coz we have already passed the rood by reference
    //so no return root

}


void createBST(Node*&root){
    int data;
    cout << "Enter the Data:";
    cin >> data;

    while(data != -1){
        // calling the insertIntoBST function 
        insertIntoBST(root,data);
        //again pushing the data
        cout << "Enter the Data:";
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
        //we will just store the frontNode and pop it so that the childs of this node can be pushed to the tree
        Node*frontNode=q.front();
        q.pop();

        if(frontNode==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            //we will be printing the frontNode coz this is not null case
            cout << frontNode->data << "->";
            //we will push the childs of the frontNode in the queue
            if(frontNode->left!=NULL){
                q.push(frontNode->left);
            }
            if(frontNode->right!=NULL){
                q.push(frontNode->right);
            }

            //we have not used else if because  we needed both if conditio to get executed
            //else if would have executed only one if case which was true even if both were true

        }
    }
}

Node*findMax(Node*&root){
    if(root==NULL){
        return NULL;
    }
    Node*temp=root;
    //if not then we have to just go to the right till we get the null and return that very Node
    while(temp->right!=NULL){
        temp=temp->right;
    }
    //when we are here means we are at our target which is max node
    return temp;
}

//we will be creating a function to delete a node from BST
Node*deleteNodefromBST(Node*root,int target){
    if(root==NULL){
        return NULL;
    }

    //if the root matches the target
    if(root->data == target){
        //  we will check where the node is so that it could be deleted accordingly
        //if the root has left but not right Subtree or has the right Subtree but non left Subtree
        // case 1
        if(root->left==NULL && root->right!=NULL){
            //we will stor the non null subtree in temp and then delete the root and return the temp
            Node*temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        }
        else if(root->left!=NULL && root->right==NULL){
            // do the same thing store the non null in temp and delete root and then return temp
            Node*temp = root->left;
            root->left = nullptr;
            delete root;
            return temp;
        }

        //Now third case is that if both the subtree left and right is NULL;
        else if(root->left==NULL && root->right == NULL){
            //then easy we have to just delete the root and return NULL
            delete root;
            return NULL;
        }

        //the main case which is when both the subtree is Non null
        else{
            //case- if(root->left==NULL && root->right == NULL)
            //in this case we have to find the max from the leftSubtree or the min from the right Subtree 
            //we are finding the maxi from left subtree from current Node
            Node*maxi = findMax(root->left);
            //and the replace the data of root from the maxi-data
            root->data = maxi->data;
            //then find the maxi for deleting so that it doesnot occurs twice,by doing the same thing, call this superior function
            //and this timeour target would be this maxi->data
            root->left = deleteNodefromBST(root->left,maxi->data);
            
        }
    }
    // Now we have to check in left and right if the target does not match
    else if(root->data >target){
        root->left = deleteNodefromBST(root->left,target);
    }
    else{
        // if(root->data >target)
        root->right = deleteNodefromBST(root->right,target);
    }

    //finally return root
    return root;
}

void BSTtoDLL(Node*root,Node*&head){
    if(root==NULL){
        return;
    }

    //we will be following RNL
    
    // R-> we will go to the rightest Node
    BSTtoDLL(root->right,head);

    // N -> we will process the current Node
    root->right=head;
    if(head!=NULL){
        //if this is not the first case then only we will do prev pointer 
        head->left = root;
    }
    head=root;   //now we will just make the current root as the head Node 


    // L->we will go for leftsubtree
    BSTtoDLL(root->left,head);
}
void printLinkedList(Node*&head){
    Node*temp=head;
    if(temp==NULL){
        cout << "there is no node to print\n";
        return;
    }
    cout << "Printing the Linked List: ";
    while(temp!=nullptr){
        cout << temp->data << "->";
        temp=temp->right;
    }
    //done printing
    cout << endl;
}


int main(){
    Node*root=NULL;
    createBST(root);

    //tree has been created
    //print the tree
    levelOrderTraversal(root);

    int target;
    cout << "enter target to delete:";
    cin >> target;

    while(target!=-1){
        root=deleteNodefromBST(root,target);
        levelOrderTraversal(root);
        cout << "enter target to delete:";
        cin >> target;
    }
    //
    Node*head = NULL;
    //now we have to create a funciton to create a DLL from bst
    BSTtoDLL(root,head);
    printLinkedList(head);
}