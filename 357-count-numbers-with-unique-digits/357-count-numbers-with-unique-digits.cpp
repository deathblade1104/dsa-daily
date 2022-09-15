class Solution {
public:
    string s;
    int dp[10][2][2][1025];
    int helper(int pos,bool tight,int st,int mask){
        
        if(pos == s.size())
            return 1;
        
        if(dp[pos][tight][st][mask]!=-1)
            return dp[pos][tight][st][mask];
        
        int upperBound  = tight ? s[pos]-'0' : 9,ans =0;
    
        if(!st){
            for(int i=0;i<=upperBound;i++){
                
                if(i==0)
                    ans+=helper(pos+1,tight&(i==upperBound),0,0);
                
                else
                    ans+=helper(pos+1,tight&(i==upperBound),1,mask|(1<<i));
            }
        }
        else {
            for(int i=0;i<=upperBound;i++){
                
                if(mask&(1<<i))
                    continue;
                
                ans+=helper(pos+1,tight&(i==upperBound),1,mask|(1<<i));
            }
        }
        
        return dp[pos][tight][st][mask] = ans;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        int temp = pow(10,n) -1;
        s = to_string(temp);
        memset(dp,-1,sizeof dp);
        
        return helper(0,1,0,0);
    }
};