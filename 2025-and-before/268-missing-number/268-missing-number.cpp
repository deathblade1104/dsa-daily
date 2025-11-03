class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long int sum = (n * (n+1))/2;
        
        for(int&i : nums)
            sum-=i;
        
        return sum;
        
    }
};