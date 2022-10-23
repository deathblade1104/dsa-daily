class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        vector<int>ans;
        int n = nums.size();
        long long sum = 0LL, total_sum = 0LL;
        
        for(int i : nums){
            
            int idx = abs(i);
            
            if(nums[idx-1]<0)
                ans.push_back(idx);
            
            else
            nums[idx-1]*=-1;
            
            sum+=abs(i);
        }
        
        
        total_sum = ((n+1) * n * 1LL)/2;
        
        ans.push_back(ans[0] + total_sum - sum);
        
        return ans;
    }
};