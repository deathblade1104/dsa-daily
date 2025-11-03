class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        mp[0] = -1;
        int last = -1,ans = 0,pref= 0;
        
        for(int i=0;i<nums.size();i++){
            pref+=nums[i];
            if(mp.count(pref - target) and mp[pref - target]>=last){
                ans++;
                last = i;
            }
            
            mp[pref] = i;
        }
        
        return ans;
    }
};