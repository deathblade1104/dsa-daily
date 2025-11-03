// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// your task is to complete this functionh
// function should return the width of the tree
int verticalWidth(Node* root);




 // } Driver Code Ends
//User function Template for C++

/*Structure of node of binary tree is as follows
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


//Function to find the vertical width of a Binary Tree.
int verticalWidth(Node* root)
{
    // Code here
    if(root==NULL) return 0;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    
    int l=0,r=0;
    
    while(q.size()>0)
    {
        pair<Node*,int>p=q.front();
        q.pop();
        
        l=min(l,p.second);
        r=max(r,p.second);
        
        if(p.first->left)
        q.push({p.first->left,p.second-1});
        
        if(p.first->right)
        q.push({p.first->right,p.second+1});
    }
    
    return r-l+1;
}

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        
        cout << verticalWidth(root) << "\n";
    }


    return 0;
}
  // } Driver Code Ends