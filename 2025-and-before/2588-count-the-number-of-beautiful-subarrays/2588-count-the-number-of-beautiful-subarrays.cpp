class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int,int>mp;    
        int pre = 0;
        mp[0] = 1;
        
        for(int&i : nums){
            
            pre^=i;
            ans+=mp[pre];
            mp[pre]++;
        }
        
        return ans;
    
    }
};