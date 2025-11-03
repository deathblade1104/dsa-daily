class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int ps=0,ans=0,release = 0;
        unordered_set<int>st;
        for(int acquire = 0;acquire<nums.size();acquire++)
        {
            while(release<acquire and st.count(nums[acquire])==1)
            {    
                ps-=nums[release];
                st.erase(nums[release++]);
            }
            
            ps+=nums[acquire];
            st.insert(nums[acquire]);
            ans = max(ans,ps);
        }
        
        return ans;
        
    }
};