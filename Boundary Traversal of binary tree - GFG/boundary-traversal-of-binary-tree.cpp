// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void get_ans(Node *root, int flag, vector<int>&lb,vector<int>&rb,vector<int>&leaves)
    {
        if(!root)
        return;
        
        if(!root->left and !root->right)
        {
            leaves.push_back(root->data);
            return;
        }
        
        if(flag==0)
        {
            lb.push_back(root->data);
            get_ans(root->left,1,lb,rb,leaves);
            get_ans(root->right,2,lb,rb,leaves);
        }
        
        else if(flag == 1)
        {
            lb.push_back(root->data);
            
            if(!root->left)
            get_ans(root->right,1,lb,rb,leaves);
            
            else
            {
                get_ans(root->left,1,lb,rb,leaves);
                get_ans(root->right,3,lb,rb,leaves);
            }
        }
        
        else if (flag==2)
        {
            rb.push_back(root->data);
            
            if(!root->right)
            get_ans(root->left,2,lb,rb,leaves);
            
            else
            {
                get_ans(root->left,3,lb,rb,leaves);
                get_ans(root->right,2,lb,rb,leaves);
            }
            
        }
        
        else
        {
            get_ans(root->left,3,lb,rb,leaves);
            get_ans(root->right,3,lb,rb,leaves);
        }
        
        return;
        
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>lb,rb,leaves;
        get_ans(root,0,lb,rb,leaves);

        vector<int>ans;
        
        for(int i=0;i<lb.size();i++)
        ans.push_back(lb[i]);
        
        
        for(int i=0;i<leaves.size();i++)
        ans.push_back(leaves[i]);
        
        for(int i=rb.size()-1;i>=0;i--)
        ans.push_back(rb[i]);
        
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends