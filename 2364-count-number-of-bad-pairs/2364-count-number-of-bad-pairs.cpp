class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        int n = nums.size();
        long long ans =0, total = ( 1L * n * (n-1)/2);
        
        for(int i=0;i<n;i++)
            ans += mp[i-nums[i]]++;
        
        return total - ans;
       
    }
};