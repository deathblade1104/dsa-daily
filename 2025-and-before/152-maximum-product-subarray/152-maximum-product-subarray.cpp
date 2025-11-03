class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int ans = INT_MIN;
        int n = nums.size(), curr;
        
        curr = 1;
        for (int i = 0; i < n; i++) {
            curr *= nums[i];
            ans = max(ans, curr);
            
            if (nums[i] == 0)
                curr = 1;
        }
        
        curr = 1;
        for (int i = n-1; i >= 0; i--) {
            curr *= nums[i];
            ans = max(ans, curr);
            
            if (nums[i] == 0)
                curr = 1;
        }
        
        return ans;
    }
};