class Solution {
public:
int f(int i,int j,const string& s, vector<vector<int>>& dp)
{
    //Base Case
    if(i==j) return 1; // if only one character is present just return 1  
    if(dp[i][j]!=-1) return dp[i][j];
    int mn=INT_MAX;
    for(int k=i;k<j;k++) //partition from i->j
    {
        mn=min(mn,f(i,k,s,dp)+f(k+1,j,s,dp)); // store the minimum
    }
    return dp[i][j]=(s[i]==s[j])?mn-1:mn;
}
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,n-1,s,dp);        
                
    }
};