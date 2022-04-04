class Solution {
public:
    int dp[1001][1001];
    int get_ans(int i, int j, string &s)
    {     
        if(j==i+1)
        {
            if(s[i]==s[j]) return dp[i][j]=1;
            
            else dp[i][j]=0;
        }
        
        if(dp[i][j]!=-1)
        return dp[i][j];        
        
        bool ans = get_ans(i+1,j-1,s);
        
        if(s[i]==s[j])
        {
            ans=true;
            ans = (ans & get_ans(i+1,j-1,s));
        }
        
        else
        {
            ans=false;       
        }
        
        bool call1 = get_ans(i+1,j,s);
        bool call2 = get_ans(i,j-1,s);
            
        return dp[i][j]=(int)ans;
        
    }
    
    int countSubstrings(string s) {
        int n=s.size();
        memset(dp,-1,1001*1001*sizeof(int));
        
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        
        int xyz= get_ans(0,n-1,s),ans = 0;     
                
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==1)
                    ans++;
            }
        }
        
        return ans;
    }
};