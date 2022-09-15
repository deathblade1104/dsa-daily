class Solution {
public:
    int dp[10][2][1025];
    string s;
    
    int helper(int pos,bool tight,int mask){
        
        if(pos == s.size())
            return 1;
        
        if(dp[pos][tight][mask]!=-1)
            return dp[pos][tight][mask];
        
        int upperBound  = tight ? s[pos]-'0' : 9,ans =0;
    
        if(mask==0){
            
            for(int i=0;i<=upperBound;i++){
                
                if(i==0)
                    ans+=helper(pos+1,tight&(i==upperBound),0);
                
                else
                    ans+=helper(pos+1,tight&(i==upperBound),mask|(1<<i));
            }
        }
        else {
            
            for(int i=0;i<=upperBound;i++){
                
                if(mask&(1<<i))
                    continue;
                
                ans+=helper(pos+1,tight&(i==upperBound),mask|(1<<i));
            }
        }
        
        return dp[pos][tight][mask] = ans;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        int temp = pow(10,n) -1;
        s = to_string(temp);
        memset(dp,-1,sizeof dp);
        
        return helper(0,1,0);
    }
};