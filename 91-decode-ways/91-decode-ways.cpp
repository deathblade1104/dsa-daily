class Solution {
public:
    int dp[101];
    int get_ans(int curr, string&s, int&sz)
    {
        if(curr>sz) return 0;
        if(curr==sz) return 1;
        if(s[curr]=='0') return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int op1=0,op2=0;        
        op1 = get_ans(curr+1,s,sz);
        if(curr+2<=sz)
        {
            string temp = s.substr(curr,2);
            int temp2= stoi(temp);
            
            if(temp2<=26)
                op2= get_ans(curr+2,s,sz);
        }
        
        return dp[curr]= op1+op2;
    }
    int numDecodings(string s) {        
        if(s[0]=='0')
          return 0;
           
        memset(dp,-1,sizeof(dp));
         int sz=s.size();
           
           return get_ans(0,s,sz);
    }
};