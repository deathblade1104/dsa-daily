class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int p_sum=0,ans=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            int curr=nums[i];
            p_sum+=curr;
            
            if(p_sum==k)
                ans++;
            
            if(mp.count(p_sum-k)==1)
                ans+=mp[p_sum-k];
            
            mp[p_sum]++;
        }
        
        return ans;
    }
};