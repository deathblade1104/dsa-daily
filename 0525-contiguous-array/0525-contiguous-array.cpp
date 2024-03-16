class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int pref = 0,ans = 0;
        unordered_map<int,int>mp;
        mp[pref] = -1;
        
        for(int i=0;i<nums.size();i++){
            
            pref+=(nums[i] == 0? -1 : 1);
              
            if(mp.count(pref)){
                ans = max(ans, i - mp[pref]);
            }
            
            else mp[pref] = i;
        }
        
        return ans;
    }
};