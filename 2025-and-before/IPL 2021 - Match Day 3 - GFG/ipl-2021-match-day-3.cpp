// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    Node *find_node(Node *root, int tar)
    {
        if(!root) return root;
        
        if(root->data==tar)
        return root;
        
        Node *l = find_node(root->left,tar);
        Node *r = find_node(root->right,tar);
        
        if(!l and !r)
        return NULL;
        
        else if (!l)
        return r;
        
        else return l;
    }
    
    void map_parents(Node *root, Node *par, unordered_map<Node*,Node*>&mp)
    {
        if(!root) return;
        
        mp[root]=par;
        
        map_parents(root->left,root,mp);
        map_parents(root->right,root,mp);
    }
    
    void get_ans(Node *root, int k, unordered_map<Node*,Node*>&mp,unordered_set<Node*>&vis, int &sum)
    {
        if(root==NULL or k<=-1 or vis.count(root)==1)
        return;

        sum+=root->data;
        vis.insert(root);
        
        get_ans(root->left,k-1,mp,vis,sum);
        get_ans(root->right,k-1,mp,vis,sum);
        get_ans(mp[root],k-1,mp,vis,sum);
    }
    
    int sum_at_distK(Node* root, int tar, int k)
    {
        // Your code goes here
        Node *target=find_node(root,tar);
        unordered_map<Node*,Node*>mp;
        
        map_parents(root,NULL,mp);
        unordered_set<Node*>vis;
        int sum=0;
        
        get_ans(target,k,mp,vis,sum);
        
        return sum;
    }


};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends