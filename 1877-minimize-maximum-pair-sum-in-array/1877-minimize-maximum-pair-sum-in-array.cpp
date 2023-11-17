class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[0] + nums.back();
        for(int i=1;i<n/2;i++){
            
            int curr = nums[i] + nums[n-i-1];
            ans = max(ans,curr);
        }
        return ans;
        
    }
};