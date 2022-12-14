class Solution {
public:
     
    unordered_map<long,int>dp[1001];
    unordered_map<long,int>mp;
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size(), ans = 0;
        
        for(int i=0;i<n;i++)
            dp[i] = mp;
            
        for(int i=1;i<n;i++){
            //cout<<nums[i]<<" :-->  "<<endl;
            for(int j=0;j<i;j++){
                long long diff = (long long) nums[i] - nums[j];
                
                if(diff <= INT_MIN or diff>=INT_MAX)
                    continue;
                
                dp[i][diff] += dp[j][diff] + 1;
                
                ans+=dp[j][diff];
                
                //cout<<nums[j]<<" # "<<diff<<" :--> "<<dp[j][diff]<<endl;
            }
            //cout<<endl;
        }
        
        return ans;
    }
};