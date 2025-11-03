// { Driver Code Starts
//Initial template for C++

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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void get_ans(Node* root, int l, int h, vector<int>&ans)
    {
        if(root==NULL)
        return;
        
        if(root->data>=l and root->data<=h)
        {
            ans.push_back(root->data);
            get_ans(root->left,l,h,ans);
            get_ans(root->right,l,h,ans);
        }
        
        else if(root->data<l)
        get_ans(root->right,l,h,ans);
        
        else get_ans(root->left,l,h,ans);
    }
    
    vector<int> printNearNodes(Node *root, int low, int high) {
        //code here   
        vector<int>ans;
        get_ans(root,low,high,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k1 , k2;
        string s;
		getline(cin,s);
		scanf("%d ", &k1);
		scanf("%d " , &k2);
		Solution ob;
        Node* root = buildTree(s);
        vector <int> res = ob.printNearNodes(root, k1 ,  k2);
        for (int i=0;i<res.size();i++) cout << res[i] << " ";
        cout<<endl;
    }
    return 1;
}
  // } Driver Code Ends