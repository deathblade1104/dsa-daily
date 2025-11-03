class Solution {
public:
    
    int helper(int i, int j, string&s1, string&s2, vector<vector<int>>&dp)
    {
        if(i>=s1.size() or j>=s2.size())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        if(s1[i]==s2[j])
        return dp[i][j] = 1 + helper(i+1,j+1,s1,s2,dp);
        
        return dp[i][j]= max(helper(i+1,j,s1,s2,dp),helper(i,j+1,s1,s2,dp));
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(),-1));
        return helper(0,0,text1,text2,dp);
        
    }
};