// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

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

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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
            // Create the left child for the current Node
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
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
    Node *LCA(Node *root, int&f, int&s)
    {
        if(!root)
        return root;
        
        if(root->data == f or root->data == s)
        return root;
        
        Node *l = LCA(root->left,f,s), *r = LCA(root->right,f,s);
        
        if(!l and !r)
        return l;
        
        else if(l and !r)
        return l;
        
        else if(!l and r)
        return r;
        
        return root;
    }
    
    bool get_path(Node *root,int&ele, vector<char>&dir)
    {
        if(!root)
        return false;
        
        if(root->data == ele)
        return true;
        
        dir.push_back('L');
        if(get_path(root->left,ele,dir))
        return true;
        
        dir.pop_back();
        dir.push_back('R');
        if(get_path(root->right,ele,dir))
        return true;
        
        
        dir.pop_back();
        return false;
    }
    
    void get_turns(vector<char>&v,int&turns)
    {
        
        // for(char&ch : v)
        // cout<<ch<<" ";
        
        // cout<<endl;
        if(v.size()!=0)
        {
            turns++;
            
            for(int i=1;i<v.size();i++)
                if(v[i]!=v[i-1])
                    turns++;
            
        }        
        return;
    }
    
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
      
      Node *common  = LCA(root,first,second);
      vector<char>d1,d2;
      
      bool f1 = get_path(common,first,d1) , f2 = get_path(common,second,d2);
      
      int turns=0;
    //   cout<<"LCA is : " <<common->data<<endl;
      
      get_turns(d1,turns);
    //   cout<<turns<<endl;
      
      get_turns(d2,turns);
      
      return turns-1;
      
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}
  // } Driver Code Ends