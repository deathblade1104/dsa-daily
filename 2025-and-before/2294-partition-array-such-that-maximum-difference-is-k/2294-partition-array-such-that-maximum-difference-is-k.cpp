class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int ans = 1, prev = nums.back();
        
        
        for(int i = nums.size()-2;i>=0;i--){
            
            if(prev - nums[i] <=k)
                continue;
            
            ans++;
            prev =nums[i];
        }
        
        return ans;
    }
};