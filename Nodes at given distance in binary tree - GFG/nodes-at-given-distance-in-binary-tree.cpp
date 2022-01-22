// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
#include<bits/stdc++.h>
class Solution
{
private:
    Node* findNode(Node *root, int tar)
    {
        if(root==NULL or root->data==tar)
        return root;
        
        Node *l=findNode(root->left,tar);
        Node *r=findNode(root->right,tar);
        
        if(l) return l;
        else if(r) return r;
        else return l;
    }
    
    void populateParent(Node *root, Node *parent, unordered_map<Node*,Node*>&mp)
    {
        if(root==NULL) return;
        
        mp[root]=parent;
        
        populateParent(root->left,root,mp);
        populateParent(root->right,root,mp);
        return;
    }
    
    void get_ans(Node* root, int k, unordered_map<Node*,Node*>&mp, unordered_set<Node*>&visited, vector<int>&ans)
    {
        if(root==NULL or k<0 or visited.find(root)!=visited.end())
        return;
        
        visited.insert(root);
        
        if(k==0)
        { 
            ans.push_back(root->data);
            return;
        }
        get_ans(root->left,k-1,mp,visited,ans);
        get_ans(root->right,k-1,mp,visited,ans);
        get_ans(mp[root],k-1,mp,visited,ans);
        
        return;
        
    }

public:
    vector <int> KDistanceNodes(Node* root, int tar , int k)
    {
        // return the sorted vector of all nodes at k dist
        
        Node *target=findNode(root,tar);
        
        unordered_map<Node*,Node*>mp;
        populateParent(root,NULL,mp);
        
        unordered_set<Node*>visited;
        vector<int>ans;
        
        get_ans(target,k,mp,visited,ans);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends