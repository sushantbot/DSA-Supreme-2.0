#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // ctor
    Node()
    {
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int x, Node *next) : data(x), next(next){}

};
// Printll
int length(Node*&head){
    Node*temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void PrintLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        // temp ko next node pe move kr denge
        temp = temp->next;
    }
    cout << endl;
}

// Insert at head
void insertathead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        // pehle newnode ke next ko head se connect krenge
        newNode->next = head;
        // head ko update kr denge
        head = newNode;
    }
}

void insertatTail(Node *&head, Node *&tail, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        // in case of empty List we will just assign newnode as tail
        head = newnode;
        tail = newnode;
    }
    else
    {
        // in case of Non empty linked list
        tail->next = newnode;
        tail = newnode;
    }
}

void deleteNodes(Node*& head, int m, int n) {
    int len=length(head);
    if (head == NULL || len < m+n) {
        return;
    }

    // Traverse m nodes
    Node* temp = head;
    int mCount = 1;
    while (mCount < m && temp != nullptr) {
        temp = temp->next;
        mCount++;
    }

    if (temp == nullptr) {
        return; // Not enough nodes to skip
    }

    // Delete n nodes
    Node* prev = temp;
    temp = temp->next;
    int nCount = 0;
    while (nCount < n && temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
        nCount++;
    }

    // Connect the previous node to the next node after deletion
    prev->next = temp;

    // Recurse for the remaining part of the list
    deleteNodes(temp, m, n);
}





int main()
{
    // i have created an empty linked list and then inserted values

Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eighth = new Node(80);
    Node *ninth = new Node(90);
    Node *tenth = new Node(100);


    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;

    Node*head=first;

    PrintLL(head);

    //CASE--->> Mujhe "m" Nodes ke baad "n" Nodes delete karne hain 
    //Dummy funciton ---> delete(head,m,n)
    deleteNodes(head,2,3);
    PrintLL(head);
    
}