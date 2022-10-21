class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if(!k)
            return false;
        
        unordered_map<int,int>mp;
        
        
        for(int i=0;i<nums.size();i++){
            
            int curr = nums[i];
        
            if(mp.count(curr)==1 and i-mp[curr]<=k)
                return true;
            
            mp[curr]=i;
        }
        
        return false;
        
    }
};