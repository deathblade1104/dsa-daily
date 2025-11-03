class Solution {
public:
    bool isPalin(string &s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
                return false;
            
            start++;
            end--;
        }
        
        return true;
    }
    
    int helper(int start, int end, string &s, vector<vector<int>>&dp)
    {
        if(start==end or isPalin(s,start,end))
        return dp[start][end] = 0;
        
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        int ans=INT_MAX;
        for(int i=start;i<end;i++)
        {
            if(isPalin(s,start,i))
            {
                int temp = 1 + helper(i+1,end,s,dp);
                ans=min(ans,temp);
            }
        }
        
        return dp[start][end] = ans;
    }
    int minCut(string s) {
        int start =0, end= s.size()-1;
        vector<vector<int>>dp(end+1, vector<int>(end+1,-1));
        
        return helper(start,end,s,dp);
        
        
               
        
        
    }
};