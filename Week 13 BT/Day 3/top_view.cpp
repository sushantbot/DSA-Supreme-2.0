#include <iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;
    //constructor
    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

//Now we will be creating tree
Node*createTree(){
    int data;
    cout << "Enter the data for Node:";
    cin >> data ;
    if (data==-1){
        return NULL;
    }

    //if not null create node for this data
    Node*root=new Node(data);

    cout << "For left of Node"<< data << ", ";
    root->left = createTree();
    

    cout << "For right of Node"<< data << ", ";
    root->right = createTree();

    return root;
}

void levelOrderTraversal(Node*&root){
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
            if(frontNode->left!=nullptr){
                q.push(frontNode->left);
            }
            if(frontNode->right!=nullptr){
                q.push(frontNode->right);
            }
        }
    }

}

void top_view(Node*&root){
    //creating a map of int,int in which we will keep track of which node has been pushded according to 
    //the levels(horizontal say hd)
    map<int,int>hdToNodemap;
    // (hd , node)
    // we will use queue and pair to store the node and its horizontal_distance(hd)
    queue<pair<Node*,int> >q;
        //     Node , hd

    //Now pushing the initial state of queue
    q.push(make_pair(root,0));

    while(!q.empty()){
        //now fetch the first pair
        pair<Node*,int>temp = q.front();
        //then we will pop the front element
        q.pop();

        Node*frontNode= temp.first;
        int hd = temp.second;
        //if there is not entry for hd in map then create
        if(hdToNodemap.find(hd)==hdToNodemap.end()){
            hdToNodemap[hd] = frontNode->data;
        }


        //taking care of the child 
        if(frontNode->left!=NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right!=NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    //Now map is fully filled
    cout <<"printing top view:";
    for(auto i:hdToNodemap){
        cout << i.second << " ";
    }
    cout << endl;
}

int main()
{
    //create Tree
    Node*rootNode= createTree();
    cout << "Printing levelOrderTraversal:\n";
    levelOrderTraversal(rootNode);

    //Now we will be printting top view
    cout << "Printing Top_view : ";
    top_view(rootNode);
    return 0;
}