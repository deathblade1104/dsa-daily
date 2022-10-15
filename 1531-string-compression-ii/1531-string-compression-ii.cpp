class Solution {
public:
    int dp[101][101][11][27];
    
    int helper(string&s,int pos,int k,int prevCount,int prev){
                
        if(pos == s.size())
            return 0;
        
        if(prevCount>=10)
            prevCount=10;
        
        if(dp[pos][k][prevCount][prev]!=-1)
            return dp[pos][k][prevCount][prev];
        
        int del = (k>0) ? helper(s,pos+1,k-1,prevCount,prev) : 101,keep = 0;
        
        if(s[pos]-'a' == prev){

            if(prevCount==1 or prevCount==9)
                keep++;
            
            keep+=helper(s,pos+1,k,prevCount+1,prev);
        }
        
        else
            keep+= 1+ helper(s,pos+1,k,1,s[pos]-'a');
        
        
        return dp[pos][k][prevCount][prev] = min(del,keep);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        
        if(k==s.size())
            return 0;
        
        if(k==0){
            
            char ch = s[0];
            int count=1,ans=0;
            
            for(int i=1;i<s.size();i++){
                
                if(ch == s[i-1])
                    count++;
                
                else
                {
                    ans+= 1;
                    if(count>1)
                    ans+=(log10(count) + 1);
                    count = 1;
                    ch = s[i];
                }   
            }
            
            ans+= 1;
            
            if(count>1)
                ans+=(log10(count) + 1);
            
            return ans;
        }
        memset(dp,-1,sizeof dp);
        return helper(s,0,k,0,26);

    }
};