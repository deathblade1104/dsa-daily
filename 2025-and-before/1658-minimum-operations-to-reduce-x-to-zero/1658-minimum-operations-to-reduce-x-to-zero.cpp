class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x;
        
        for(int&i: nums)
            target+=i;
        
        if(target<0)
            return -1;
        
        if(target == 0)
            return nums.size();
        
        unordered_map<int,int>mp;
        int sz=nums.size(),ps=0,res = INT_MIN;
        
        for(int i=0;i<sz;i++)
        {
            ps+=nums[i];
            
            if(ps == target)
                res = i+1;
            
            else if(mp.count(ps - target)==1)
                res = max(res,( i - mp[ps- target]));
            
            mp[ps] = i;
        }
        
        return res == INT_MIN? -1 : sz-res;
     }
};