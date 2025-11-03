//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int dp[8][2][2][10];
    string s1,s2;
    
    int helper(int pos,bool tight, bool hasStarted,int prev,string&s){
        
        if(pos>=s.size())
            return 1;
            
        if(dp[pos][tight][hasStarted][prev]!=-1)
            return dp[pos][tight][hasStarted][prev];
            
        int upperBound  = tight ? s[pos]-'0' : 9,ans =0;
        
        if(!hasStarted){
            for(int i=0;i<=upperBound;i++){
                ans+=helper(pos+1,tight && (i==upperBound),hasStarted | i>0,i,s);
            }
        }
        
        else{
            for(int i=max(0,prev-1);i<=min(prev+1,upperBound);i++)
                if(abs(i-prev)==1){
                    ans+=helper(pos+1,tight && (i==upperBound),1,i,s);
                }
        }
        
        
        return dp[pos][tight][hasStarted][prev] = ans;
    }
    int steppingNumbers(int n, int m)
    {
        s2 = to_string(m);

        memset(dp,-1,sizeof dp);
        int ans = helper(0,1,0,0,s2);
        n--;
        if(n>=0){
            s1 = to_string(n);
            memset(dp,-1,sizeof dp);
            ans-=helper(0,1,0,0,s1);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends