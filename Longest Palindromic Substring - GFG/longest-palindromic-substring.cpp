// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int get_ans(int i, int j, string &s,vector<vector<int>>&dp)
    {
        if(i>j) return 0;       
        
        if(i==j)
        return dp[i][j]=1;
        
        if(j==i+1)
        {
            if(s[i]==s[j]) return dp[i][j]=1;
            
            else dp[i][j]=0;
        }
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        bool ans;
        
        if(s[i]==s[j])
        {
            ans=true;
            ans = (ans & get_ans(i+1,j-1,s,dp));
        }
        
        else
        {
            ans=false;       
            bool call3 = get_ans(i+1,j-1,s,dp);
        }
        
        bool call1 = get_ans(i+1,j,s,dp);
        bool call2 = get_ans(i,j-1,s,dp);
            
        return dp[i][j]=(int)ans;
        
    }
    
    string longestPalindrome(string s){
        // code here 
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        int xyz= get_ans(0,n-1,s,dp),ans = 1;      
        string temp="";
        temp+=s[0];
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dp[i][j] == 1 and j-i+1>ans)
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