// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


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

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    Node *findTar(Node * root, int target)
    {
        if(root==NULL) return NULL;
        
        if(root->data==target) return root;
        
        Node *l = findTar(root->left,target);
        Node *r = findTar(root->right,target);
        
        if(l) return l;
        else if (r) return r;
        return NULL;
    }
    
    void mapParents(Node *root, Node* par, unordered_map<Node*,Node*>&mp)
    {
        if(root==NULL) return;
        
        mp[root]=par;
        
        mapParents(root->left,root,mp);
        mapParents(root->right,root,mp);
        
        return;
    }
    
    void get_ans(Node *root, int count, int&ans, unordered_map<Node*,Node*>&mp, unordered_set<Node*>&vis)
    {
        if(root==NULL or vis.count(root)==1)
        return;
        
        vis.insert(root);
        ans=max(count,ans);
        
        // cout<<root->data<<" "<<count<<endl;
        
        get_ans(root->left,count+1,ans,mp,vis);
        get_ans(root->right,count+1,ans,mp,vis);
        get_ans(mp[root],count+1,ans,mp,vis);
        return;
        
        
    }
    int minTime(Node* root, int tar) 
    {
        // Your code goes here
        
        Node *target= findTar(root,tar);
        unordered_map<Node*,Node*>mp;
        mapParents(root,NULL,mp);
        
        unordered_set<Node*>vis;
        
        int ans=0;
        get_ans(target,0,ans,mp,vis);
        
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends