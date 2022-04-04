class Solution {
public:
    int dp[1001][1001];
    int get_ans(int i, int j, string &s)
    {
        if(i>j) return 1;     
               
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        bool ans;
        
        if(s[i]==s[j])
        {
            ans=true;
            ans = (ans & get_ans(i+1,j-1,s));
        }
        
        else
        ans=false;       
        
        bool call1 = get_ans(i+1,j,s);
        bool call2 = get_ans(i,j-1,s);
            
        return dp[i][j]=(int)ans;
        
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        memset(dp,-1,1001*1001*sizeof(int));
        
        int xyz= get_ans(0,n-1,s),ans = 1;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//                 cout<<dp[i][j]<<" ";
            
            
//             cout<<endl;
//         }
        
        string temp="";
        temp+=s[0];
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dp[i][j] == 1 and j-i+1>ans)
                {
                    ans=j-i+1;
                    temp=s.substr(i,j-i+1);
                }
               
            }
        }
        
        return temp;
    }
};