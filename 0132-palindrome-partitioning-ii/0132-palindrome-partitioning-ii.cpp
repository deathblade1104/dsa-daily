class Solution {
public:
    int dp[2001];
    bool isPalindrome(int i, int j,string&s){
        
        while(i<j){
            if(s[i]!=s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    int helper(int curr,string&s){
        
        if(curr>=s.size())
            return -1;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int ans = INT_MAX;
        
        for(int i=curr;i<s.size();i++){
            if(isPalindrome(curr,i,s)){
                int t = 1 + helper(i+1,s);
                ans = min(ans,t);
            }
        }
        
        return dp[curr] = ans;
    }
    int minCut(string s) {
        
        memset(dp,-1,sizeof dp);
        return helper(0,s);
        
    }
};