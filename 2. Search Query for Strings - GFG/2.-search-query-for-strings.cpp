// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;
// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *, string key);

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *, string key);

// Driver
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();

        // Construct trie
        for (int i = 0; i < n; i++) insert(root, keys[i]);

        while (q--) {
            string key;
            cin >> key;
            if (search(root, key))
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++


//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    // code here
    for(int i=0;i<key.size();i++)
    {
        char x = key[i];
        
        if(root->children[x-'a']==NULL)
            root->children[x-'a'] = new TrieNode();
        
        root=root->children[x-'a'];
    }
  
   root->isEndOfWord=true;
   return;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{

    for(int i=0;i<key.size();i++)
    {
        char x = key[i];
        if(root->children[x-'a']==NULL)
            return false;
            
        root=root->children[x-'a'];
    }
    return root->isEndOfWord;
}

