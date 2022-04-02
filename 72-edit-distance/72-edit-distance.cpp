class Solution {
public:
    int dp[501][501];
    
    int get_ans(int i,int j, string &s1, string &s2)
    {      
        if(i==s1.size())
            return s2.size()-j;
        
        if(j==s2.size())
            return s1.size()-i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
            
        if(s1[i]==s2[j])
            ans=get_ans(i+1,j+1,s1,s2);
        
        else
        ans=1 +min({get_ans(i,j+1,s1,s2),get_ans(i+1,j,s1,s2),get_ans(i+1,j+1,s1,s2)});
        
        
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,501*501*sizeof(int));
        
        return get_ans(0,0,word1,word2);
    }
};