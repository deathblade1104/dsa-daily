class Solution {
public:
    
    int dp[10001][101];
    
    int getAns(int curr,int val,int&sz,vector<int>&arr){
        
        
        if(val == 0)
            return 0;
        
        if(curr>=sz)
            return 102;
        
        if(dp[val][curr]!=-1)
            return dp[val][curr];
        
        int op1 = 102,op2=102;
        
        if(arr[curr]<=val){
            op1= 1+ getAns(curr,val-arr[curr],sz,arr);
        }
        
        op2 = getAns(curr+1,val,sz,arr);
        
        return dp[val][curr] = min(op1,op2);
        
    }
    
    int numSquares(int n) {
        
        vector<int>arr;
        for(int i=1;i*i<=n;i++)
            arr.push_back(i*i);
        
        int sz = arr.size();
        sort(arr.rbegin(),arr.rend());
        memset(dp,-1,sizeof dp);
        
        return getAns(0,n,sz,arr);   
    }
};