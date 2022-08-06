class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
           
        long long ans =0;
        unordered_map<int,int>mp;
        
        mp[nums[0]] = 1;
        for(int i=1;i<nums.size();i++)
        {
            int diff = nums[i] - i;
            ans += i - mp[diff];
            
            mp[diff]++;
        }
        
        return ans;
    }
};