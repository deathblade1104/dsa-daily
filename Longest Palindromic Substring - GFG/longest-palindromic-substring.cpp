// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
            dp[i][i] = true;                   
        
        
        for(int sz=2;sz<=n;sz++)
        {
            for(int i=0;i+sz-1<n;i++)
            {
                int start=i,end=i+sz-1;                       
                
                if(sz==2)
                dp[start][end]=(s[start]==s[end]);
        
                else
                dp[start][end]=(s[start]==s[end])&&(dp[start+1][end-1]);
            }    
        }
        
        int ans = 1;
        string temp="";
        temp+=s[0];
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dp[i][j] and j-i+1>ans)
                {
                    ans=j-i+1;
                    temp=s.substr(i,j-i+1);
                }
               
            }
        }
        
        return temp;
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends