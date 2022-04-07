class Solution {
public:
    int dp[101][10001];	
	int getans(vector<int>&v,int curr,int sz,int n)
	{
	    if(n==0)
	    return 0;
	    
	    if(curr>=sz)
	    return 10001;
	    
	   if(dp[curr][n]!=-1)
	   return dp[curr][n];
	    
	    int same=10001;
	    
	    if(v[curr]<=n)
	    same = 1 + getans(v,curr,sz,n-v[curr]);
	    
	    int not_same = getans(v,curr+1,sz,n);
	    
	    dp[curr][n]= min(same,not_same);
	    
	    return dp[curr][n];
	}
    
    int numSquares(int n)
    {
       int lim;
	    lim=floor(sqrt(n));
	    
	    vector<int>v;
	    
	    for(int i=1;i<=lim;i++)
	    v.push_back(i*i);
	    
	    int sz=v.size();
	    
	    for(int i=0;i<sz;i++)
	        for(int j=0;j<=n;j++)
	            dp[i][j]=-1;
	  
	    
	    int ans= getans(v,0,sz,n);
	    
	    return ans;
    }
};