class Solution {
private: 
    static int sum,n,target;
    static array<array<int,1501>,31>dp;
    
    int helper(int curr,int currSum,vector<int>&nums){
      
        
        if(currSum>=target || curr>=n)
            return abs(currSum - (sum - currSum));
        
        if(dp[curr][currSum]!=-1)
            return dp[curr][currSum];
        
        
        int ans = helper(curr+1,currSum+nums[curr],nums);
        ans = min(ans,helper(curr+1,currSum,nums));
        
        return dp[curr][currSum] = ans;
    }
    
    
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        n = stones.size();
        sum = 0;
        
        for(int&i : stones){
            sum+=i;
        }
        
        target = ceil(sum/2);
       
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=target;j++){
                dp[i][j] = -1;
            }
        }
        
        
        return helper(0,0,stones);        
    }
};

int Solution::sum;
int Solution::n;
int Solution::target;
array<array<int,1501>,31> Solution::dp;