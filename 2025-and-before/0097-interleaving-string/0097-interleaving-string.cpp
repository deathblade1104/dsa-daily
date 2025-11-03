class Solution {
public:
    int dp[101][101];
    int m,n,o;
    
    bool helper(int i,int j,string&s1,string&s2,string&s3){
        int k = i + j;
        
        if(k>=o and i>=m and j>=n)
            return true;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool op1= false,op2 = false;
        
        if(i<m and s1[i]==s3[k])
            op1 = helper(i+1,j,s1,s2,s3);
        
         if(j<n and s2[j]==s3[k])
            op2= helper(i,j+1,s1,s2,s3);
        
        return dp[i][j] = false | op1 | op2;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof dp);
        o= s3.size(),m = s1.size(),n = s2.size();
        
        if(o!=m + n)
            return false;
        
        return helper(0,0,s1,s2,s3);
        
    }
};