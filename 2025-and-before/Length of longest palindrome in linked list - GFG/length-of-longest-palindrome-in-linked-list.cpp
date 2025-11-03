// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
#include<bits/stdc++.h>
bool helper(vector<int>&S,int l, int r, vector<vector<int>>&dp)
{
    if(l == r)
    return dp[l][r]=true;
    
    if(l + 1 == r)
    {
        if(S[l] == S[r])
        return dp[l][r] = true;
        
        return dp[l][r] = false;
    }
    
    if(dp[l][r]!=-1)
    return dp[l][r];
    
    bool ans = false;
    if(S[l] == S[r])
    ans = true and helper(S,l+1,r-1,dp);
    
    bool call1 = helper(S,l+1,r,dp) , call2 =helper(S,l,r-1,dp); 
    
    return dp[l][r] = ans;
}

int LPS (vector<int>&S)
{
        // code here
    int n = S.size(),res=1;
    
    vector<vector<int>>dp(n,vector<int>(n,-1));
    bool temp = helper(S,0,n-1,dp);
    
    string ans = "";
                
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(dp[i][j]==1 and j - i + 1 > res)
                res = j - i + 1;
        }
    }
     
     return res;
}

int maxPalindrome(Node *head)
{
    //Your code here
    vector<int>v;
    Node *curr = head;
    
    while(curr)
    {
        v.push_back(curr->data);
        curr = curr->next;
    }
    
    return LPS(v);
}