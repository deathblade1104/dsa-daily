class Solution {
public:
    int dp[1001][1001];
    
    int get_ans(int i, int j, string&s,int&n)
    {
        if(i>=n or j<0)
            return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
                
        if(s[i]==s[j]) 
            return dp[i][j]=  1 + get_ans(i+1,j-1,s,n);
        
        return dp[i][j]= max(get_ans(i+1,j,s,n), get_ans(i,j-1,s,n));
        
    }
    
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        memset(dp,-1,sizeof dp);
        
        return get_ans(0,n-1,s,n);
    }
};