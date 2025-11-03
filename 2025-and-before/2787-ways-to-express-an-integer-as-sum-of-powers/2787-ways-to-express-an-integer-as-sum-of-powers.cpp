class Solution {
public:
    
    
    int sz;
    vector<int>nums;
    const int mod = 1e9+7;
    
    int helper(int curr,int sum,vector<vector<int>>&dp){
        
        if(sum == 0)
            return 1;
        
        if(curr>=sz)
            return 0;
        
        if(dp[curr][sum]!=-1)
            return dp[curr][sum];
        
        //cout<<nums[curr]<<" "<<sum<<endl;
        
        int op1 = 0;
        
        if(nums[curr]<=sum)
            op1  = helper(curr+1,sum - nums[curr],dp);
        
        int op2 = helper(curr+1,sum,dp);
        
        return dp[curr][sum] = (op1 + op2)%mod;
    }
    
    
    int numberOfWays(int n, int x) {
        
        nums.clear();
        int i=1;
        
        while(true){
            
            int currNum = pow(i,x);
            
            if(currNum>n)
                break;
            
            nums.push_back(currNum);
            i++;
        }
        sz = nums.size();
        
        //cout<<nums.size()<<endl;
        
        vector<vector<int>>dp(sz,vector<int>(n+1,-1));
        
        return helper(0,n,dp);
    }
};