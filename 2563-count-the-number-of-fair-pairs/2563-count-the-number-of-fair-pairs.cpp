class Solution {
private: 
    int n;
    
    long long helper(vector<int>&nums,int val){
        
        long long ans = 0LL;
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            if (nums[left] + nums[right] > val) {
                // If the sum exceeds the value, move the right pointer to decrease the sum
                right--;
            } else {
                // All pairs (left, left+1), (left, left+2), ..., (left, right) are valid
                ans += 1LL*(right - left);
                left++;
            }
        }
        
        
        return ans;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        n = nums.size();
        sort(nums.begin(),nums.end());
        return helper(nums,upper) - helper(nums,lower-1);
        
        
    }
};