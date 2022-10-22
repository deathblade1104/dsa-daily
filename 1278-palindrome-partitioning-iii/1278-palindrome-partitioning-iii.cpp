class Solution {
public:

    int dp[101][101];

    int palinHelper(int i, int j, string&s){
        
        int ans = 0;
        
        while(i<j){
            
            if(s[i]!=s[j])
                ans++;
            
            i++;
            j--;
        }
        
        return ans;
    }
    
    int helper(int curr,int k,string&s){
        
        if(curr==s.size())
            return k!=0;
        
        if(dp[curr][k]!=-1)
            return dp[curr][k];
        
        int ans = 102;
        for(int i=curr;i<s.size();i++){
            
            if(k>0){
                int x = palinHelper(curr,i,s);
                int temp = x + helper(i+1,k-1,s);
                                
                ans = min(ans,temp);
            }
        }
        
        return dp[curr][k]=ans;
    }
    int palindromePartition(string s, int k) {
        
        if(k==s.size())
            return 0;
        
        memset(dp,-1,sizeof dp);
        
        return helper(0,k,s);
        
    }
};