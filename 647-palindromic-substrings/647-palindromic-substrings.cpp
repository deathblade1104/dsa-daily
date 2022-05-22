class Solution {
public:
    
    bool helper(int i, int j, string&s, vector<vector<int>>&dp)
    {
        if(i == j)
            return dp[i][j]=1;
        
        if(i == j-1)
        {
            if(s[i]==s[j])
                return dp[i][j]=1;
            
            return dp[i][j]=0;
        }
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        bool ans;
        
        if(s[i]==s[j])
        {
           ans= true and helper(i+1, j-1,s,dp);
        }
        
        else ans = false;
        
        bool call1 = helper(i,j-1,s,dp), call2 = helper(i+1,j,s,dp);
        
        return dp[i][j] = (int)ans;
    }
    int countSubstrings(string s) {
               
        int low = 0 , high = s.size() - 1;
        vector<vector<int>>dp(high+1, vector<int>(high+1,-1));
        bool call  = helper(low,high,s,dp);        
        int ans = high + 1;
        
        for(int i=0;i<=high;i++)
        {
            for(int j =i+1;j<=high;j++)
                if(dp[i][j])
                    ans++;
        }
        
        return ans;
        
    }
};