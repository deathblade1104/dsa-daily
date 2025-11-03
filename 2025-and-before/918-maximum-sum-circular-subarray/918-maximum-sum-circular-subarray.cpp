class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
    int cur_sum = nums[0];
        int best = nums[0];
        int nums_size = nums.size();
        int cur_idx;
        
        //Use Kadane's method with out consider the circular condition. 
        for(int i=1; i<nums_size; i++) {
            cur_sum = max(cur_sum + nums[i], nums[i]);
            best = max(cur_sum, best);
        }


        //Use Kadane's method for the case subarray is circular.
        int nums_sum = 0;
        for(int& num: nums) {
            nums_sum += num;
        }

        cur_sum = nums_sum;
        for(int i=1; i<nums_size-1; i++) {
            cur_sum = max(nums_sum - nums[i], cur_sum - nums[i]);
            best = max(cur_sum, best);
        }

        return best;
    }
};