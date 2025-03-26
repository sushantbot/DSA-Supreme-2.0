#include <iostream>
using namespace std;

class TrieNode
{
public:
    char value;             // we will store characters inside this
    TrieNode *children[26]; // there could be 26 children for every roots
    bool isTerminal;

    // constructor
    TrieNode(char val)
    {
        this->value = val;
        // default for children node
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL; // initialised every node by NULL in default case
        }
        this->isTerminal = false; // means by default every node is false
    }
};
void insertIntoTrieNode(TrieNode *root, string word)
{
    cout << "Received word : " << word << ", for Insertion\n";
    // if the word length is 0 then we need to make it terminal and return
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }
    // here we will be checking if the character is present or not
    char ch = word[0];
    int index;
    if (ch >= 65 && ch <= 90)
    {
        index = ch - 'A';
    }
    else
    {
        index = ch - 'a';
    }

    TrieNode *child;
    if (root->children[index] != NULL)
    {
        // this means that the word character already present
        // so only traverse
        child = root->children[index];
    }
    else
    {
        // this means absent
        // so create and then traverse
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursive calls for further nodes
    // substr(1) :- means it passes the word without 1 character from starting
    insertIntoTrieNode(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal; // if true or false
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode *child;
    if (root->children[index] != NULL)
    {
        // present or found
        child = root->children[index];
    }
    else
    {
        // absent
        return false;
    }

    // Now recursive calls
    return searchWord(child, word.substr(1));
}

void deleteWord(TrieNode*root,string word){
    if(word.length()==0){
        //just make the isterminal of that very character false so that the word wont exist
        root->isTerminal=false;
        return;
    }

    char ch = word[0];
    int index= ch-'a';

    //checking if the character exists or not
    TrieNode*child;
    if(root->children[index]!=NULL){
        //this means that the character is present
        //so we will make this our child
        child = root->children[index];
    }
    else{
        //not found
        //noithing to do just return 
    }

    //now recursive call
    deleteWord(child,word.substr(1));

}

int main()
{
    // string word;
    // cout << "Enter Words : ";
    // getline(cin, word);

    TrieNode *root = new TrieNode('-');

    // while(word != "-1"){
    // insertIntoTrieNode(root,word);

    //     //again take input to feed the words
    //     cout << "Enter Words : ";
    //     getline(cin,word);
    // }
    insertIntoTrieNode(root, "cater");
    insertIntoTrieNode(root, "care");
    insertIntoTrieNode(root, "com");
    insertIntoTrieNode(root, "lover");
    insertIntoTrieNode(root, "loved");
    insertIntoTrieNode(root, "load");
    insertIntoTrieNode(root, "lov");
    insertIntoTrieNode(root, "bat");
    insertIntoTrieNode(root, "cat");
    insertIntoTrieNode(root, "car");

    cout << "Insertion of words done:" << endl;

    string str;
    cout << "Enter word to Search for : ";
    getline(cin,str);

    if (searchWord(root, str))
    {
        cout << "Found " << endl;
    }
    else
    {
        cout << "Not Found " << endl;
    }

    //function call to delete word
    deleteWord(root,str);

    if (searchWord(root, str))
    {
        cout << "Found " << endl;
    }
    else
    {
        cout << "Not Found " << endl;
    }


}