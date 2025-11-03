class Solution {
public:
    int dp[501][501];
    int N,M;
    
    int helper(int i,int j,string&s1,string&s2){
        
         if(i>=N)
            return M - j;
        
        if(j>=M)
            return N - i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        if(s1[i]==s2[j])
            return dp[i][j] = helper(i+1,j+1,s1,s2);
        
        
        return dp[i][j] = 1 + min(helper(i,j+1,s1,s2),helper(i+1,j,s1,s2));
    }
    
    int minDistance(string word1, string word2) {
        
        N = word1.size();
        M = word2.size();
        memset(dp,-1,sizeof dp);
        return helper(0,0,word1,word2);
        
    }
};