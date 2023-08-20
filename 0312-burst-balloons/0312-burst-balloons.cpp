class Solution {
public:
    int N;
    int dp[303][303];
    int helper(int first,int last,vector<int>&nums){
        
        if(first>last)
            return 0;
        
        if(dp[first][last]!=-1)
            return dp[first][last];
        
        int ans = 0;
        for(int i=first;i<=last;i++){
            int curr = nums[first-1]*nums[i]*nums[last+1];
            curr+=helper(first,i-1,nums);
            curr+=helper(i+1,last,nums);
            ans = max(ans,curr);
        }
        
        return dp[first][last] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(dp,-1,sizeof dp);
        
        N = nums.size() - 1;
        
        for(int i=1;i<=N-1;i++){
            int temp = nums[i];
            
            if(i - 1 >= 0)  
                temp *= nums[i - 1];
            
            if(i + 1 < N)
                temp *= nums[i + 1];
            
            dp[i][i] =  temp;
        }
        
        return helper(1,N-1,nums);
    }
};