class Solution {
public:
    int dp[1001][1001];
    int get_ans(int i, int j, string &s)
    {  
        if(i==j)
        return dp[i][j]=1;
        
        if(j==i+1)
        {
            if(s[i]==s[j]) return dp[i][j]=1;
            
            else return dp[i][j]=0;
        }
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        bool ans=false;
        
        if(s[i]==s[j])
        ans=true & get_ans(i+1,j-1,s);      
            
        bool call1 = get_ans(i+1,j,s);
        bool call2 = get_ans(i,j-1,s);
            
        return dp[i][j]=(int)ans;
        
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        memset(dp,-1,1001*1001*sizeof(int));
        
        int xyz= get_ans(0,n-1,s),start=-1,end=-1,res=0;;      
        string ans = "";
                
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dp[i][j]==1 and j - i + 1 > res)
                {
                    end = j;
                    start = i;
                    res = j - i + 1;
                }
               
            }
        }
        
        if(end!= -1 and start!=-1)
            ans= s.substr(start,res);
        
        else
            ans+=s[0];
        
        return ans;
        
    }
};