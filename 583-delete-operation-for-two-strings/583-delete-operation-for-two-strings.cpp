class Solution {
public:
    int dp[501][501];
    int helper(int i, int j,string&word1,string&word2)
    {
        if(i>=word1.size())
            return word2.size() - j;
        
        if(j>=word2.size())
            return word1.size() - i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans =0;
        
        if(word1[i]==word2[j])
            ans = helper(i+1,j+1,word1,word2);
        
        else
            ans = 1 + min(helper(i+1,j,word1,word2), helper(i,j+1,word1,word2));
        
        return dp[i][j] = ans;
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,501*501*sizeof(int));
        return helper(0,0,word1,word2);
    }
};