class Solution {
public:
    int countAtmost(vector<int>&nums, int k)
    {
        int ans=0,start=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            
            while(mp.size()>k)
            {
                if(mp[nums[start]]>1)
                    mp[nums[start]]--;
                
                else if(mp[nums[start]]==1)
                    mp.erase(nums[start]);
                
                start++;
            }
            
            ans+=(i - start + 1);            
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return countAtmost(nums,k) - countAtmost(nums,k-1);
        
    }
};