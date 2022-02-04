class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                nums[i]=-1;
        }
        
        int p_sum=0,ans=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            p_sum+=nums[i];
            
            if(p_sum==0)
                ans=max(ans,i+1);
            
            if(mp.count(p_sum)==1)
                ans=max(ans,(i-mp[p_sum]));
            
            else
                mp[p_sum]=i;           
        }
        
        return ans;
        
    }
};