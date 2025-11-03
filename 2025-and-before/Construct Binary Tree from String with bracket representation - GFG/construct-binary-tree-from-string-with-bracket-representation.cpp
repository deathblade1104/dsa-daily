// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // function to construct tree from string
    
    int get_num(string &str, int&idx)
    {
        int num=0;
        while(idx<str.size() and isdigit(str[idx]))
        {
            num*=10;
            num+=str[idx] - '0';
            
            idx++;
        }
        return num;
    }
    
    Node *helper(string &str, int&idx)
    {
        if(str[idx]==')')
        {
            idx++;
            return NULL;
        }
        
        if(isdigit(str[idx]))
        {
            int num = get_num(str,idx);
            Node* root = new Node(num);
            
            if(idx<str.size() and str[idx]=='(' and root->left == NULL)
            {
                idx++;
                root->left = helper(str,idx);
                idx++;
            }
                
            if(idx<str.size() and str[idx]=='(' and root->right == NULL)
            {
                idx++;
                root->right = helper(str,idx);
                idx++;
            }
            return root;
        }
    }
    Node *treeFromString(string str)
    {
        int idx=0;
        return helper(str,idx);
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends