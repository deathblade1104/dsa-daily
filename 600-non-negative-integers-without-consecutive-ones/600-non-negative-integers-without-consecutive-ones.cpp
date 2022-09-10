class Solution {
public:
    int dp[32][2][2];
    
    string decimalToBinary(int n){
        string ans = "";
        int i = 0;
        while (n > 0) {
            int curr = (n % 2);
            n = n / 2;
            i++;
            ans+=(char)(curr + '0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int helper(int pos,bool repetitive,bool tight, string&s){
        
        if(pos == s.size())
            return 1;
        
        if(dp[pos][repetitive][tight]!=-1)
            return dp[pos][repetitive][tight];
        
        int ans = 0,ub =1;
        
        if(tight)
            ub = (int)(s[pos] - '0');
        
        for(int i=0;i<=ub;i++){
            
            if(i==1 and repetitive)
                continue;
            
            ans+=helper(pos+1,(i==1),tight&&(i == ub),s);
        }
        
        return dp[pos][repetitive][tight] = ans;
    }
    
    int findIntegers(int n) {
        
        string s = decimalToBinary(n);

        memset(dp,-1,sizeof dp);
        
        return helper(0,false,true,s);
    }
};