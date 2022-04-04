class Solution {
public:
    int dp[1001][1001];
    
    int get_value(int itr, string&s)
    {
        int ans=0;
        
        while(itr!=s.size())
            ans+=((int)s[itr++]);
        
        return ans;
    }

    int get_ans(int i, int j, int&n,int&m, string &s1, string &s2)
    {
        if(i>=n)
            return get_value(j,s2);
        
        if(j>=m)
            return get_value(i,s1);
        
        if(dp[i][j]!=-1) return  dp[i][j];
        
        int ans = 0;
        if(s1[i]==s2[j])
            ans = get_ans(i+1,j+1,n,m,s1,s2);
        
        else
        {
            int op1=(int)s1[i],op2=(int)s2[j];
            
            op1+=get_ans(i+1,j,n,m,s1,s2);
            op2+=get_ans(i,j+1,n,m,s1,s2);
            
            ans=min(op1,op2);
        }
        
        return dp[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        memset(dp,-1,1001*1001*sizeof(int));
        
        
        return get_ans(0,0,n,m,s1,s2);
        
    }
};