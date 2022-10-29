//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    struct TrieNode{
        
        TrieNode *children[26];
        vector<string>pref;
        
        TrieNode(){
            
            for(int i=0;i<26;i++)
                children[i]= NULL;
                
            pref.clear();
        }
    };
    
    TrieNode *root;
    
    void insert(TrieNode *root,string s){
        
        TrieNode *curr = root;
        for(char&ch : s){
            
            int i = ch - 'a';
            if(!curr->children[i])
                curr->children[i] = new TrieNode();
                
            curr = curr->children[i];
            curr->pref.push_back(s);
        }
    }
    
    
    void getAns(TrieNode *root,string&s,vector<vector<string>>&ans){
        
        TrieNode *curr = root;
        for(char&ch : s){
            
            int i = ch - 'a';
            
            if(!curr->children[i])
                curr->children[i] = new TrieNode();
        
            curr = curr->children[i];
            
            if(curr->pref.size())
                ans.push_back(curr->pref);
            
            else
                ans.push_back({"0"});
        }
        
        return;
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        set<string>str(contact,contact+n);
        root = new TrieNode();
        
        set<string>::iterator itr;
        for (itr = str.begin();itr != str.end(); itr++)
            insert(root,*itr);

        vector<vector<string>>ans;
        getAns(root,s,ans);

        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends