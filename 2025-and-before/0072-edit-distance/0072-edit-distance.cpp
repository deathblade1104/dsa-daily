class Solution {
public:
    int dp[501][501];
    int n1, n2;
    int helper(int i,int j,string&s1,string&s2){
        
         if(i==n1)
            return n2-j;
        
        if(j==n2)
            return n1-i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = helper(i+1,j+1,s1,s2);
        
        else return dp[i][j] = 1 + min({helper(i,j+1,s1,s2), helper(i+1,j,s1,s2), helper(i+1,j+1,s1,s2)});
    }
    int minDistance(string&word1, string&word2) {
        n1 = word1.size();
        n2 = word2.size();
        memset(dp,-1,sizeof dp);
        return helper(0,0,word1,word2);
    }
};