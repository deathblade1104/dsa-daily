class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int,int>mp;
        
        int ans  = 0,pref  = 0;
        for(int&i : nums){
            
            pref+=i;
            
            if(pref == goal)
                ans++;
            
            if(mp.count(pref - goal))
                ans+=mp[pref - goal];
            
            mp[pref]++;
        }
        
        return ans;
    }
};