class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        for(int x:nums)
            mp[x]++;
        
        int sz=0;
        
        if(nums.size()&1)
            sz=(nums.size()+1)/2;
        else sz=nums.size()/2;
        
        for(auto itr : mp)
            if(itr.second>=sz)
               return itr.first;
               
        return -1;
    }
};