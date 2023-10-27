class Solution {
public:
    int dp[1001][1001];
    
    bool helper(int i,int j,string&s){
        
         if(i>j)
            return false;
        
        if(i==j)
            return dp[i][j] = true;
        if(j == i+1)
            return dp[i][j] = s[i]==s[j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        helper(i+1,j,s);
        helper(i,j-1,s);
        
        if(s[i]==s[j])
            dp[i][j] = true & helper(i+1,j-1,s);
        
        else dp[i][j] = 0;
        
        return dp[i][j];
    }
    
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof dp);
        int n = s.size();
        helper(0,n-1,s);
        
        int ans = 1;
        string curr = "";
        curr+=s[0];
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(dp[i][j] and j-i+1>ans){
                    curr = s.substr(i,j-i+1);
                    ans = j - i + 1;
                }
            }
        }
        
        return curr;
    }
};