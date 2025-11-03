class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int,int>mp;
        mp[0] = 1;
        int ans  = 0,pref  = 0;
        for(int&i : nums){
            
            pref+=i;
            
            
            if(mp.count(pref - goal))
                ans+=mp[pref - goal];
            
            mp[pref]++;
        }
        
        return ans;
    }
};