class Solution {
public:
     int dp[1001][1001];
    
    int get_ans(int i, int j, string&s1,string&s2,int&n,int&m)
    {
        if(i>=n or j>=m)
            return dp[i][j]=0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        
        if(s1[i]==s2[j]) 
            ans = 1 + get_ans(i+1,j+1,s1,s2,n,m);
        
        else 
            ans = max(get_ans(i+1,j,s1,s2,n,m), get_ans(i,j+1,s1,s2,n,m));
        
        return dp[i][j]=ans;
    }
    
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s2= s;
        reverse(s2.begin(),s2.end());
        memset(dp,-1,1001*1001*sizeof(int));
        
        return get_ans(0,0,s,s2,n,n);
    }
};