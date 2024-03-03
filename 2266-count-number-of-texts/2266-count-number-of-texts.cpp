class Solution {
    private: 
    int n;
    static const int mod = 1e9 + 7;
    static int dp[(int)1e5 +1];
    
    int getVal(char&ch){
        return ch - '0';
    }
        
    int helper(int curr,string&str){
        
        if(curr>=n)
            return 1;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int currVal = getVal(str[curr]);
        int maxi = (currVal == 7 || currVal == 9) ? 4 : 3, ans = 0,i=1,idx = curr;
            
        while(i <= maxi && str[idx] == str[curr]) {
            ++idx;
            ++i;
            ans= (ans%mod + helper(idx,str)%mod)%mod;
        }
        
        
        return dp[curr]= ans;   
    }
    
    public: 
    int countTexts(string str) {
        memset(dp,-1,sizeof dp);    
        n = str.size() - 1;
        
        return helper(0,str);
    }
};

int Solution::dp[(int)1e5 +1];