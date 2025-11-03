class Solution {
public:
    void helper(int curr, int&sz, vector<int>&nums, vector<vector<int>>&ans)
    {
         if(curr == sz-1)
         {
             ans.emplace_back(nums);
             return;
         }
        
         unordered_set<int>st;
         for(int i = curr; i<sz; i++)
         {
             if(st.count(nums[i])==1)
                 continue;
             
             st.insert(nums[i]);
             swap(nums[i],nums[curr]);
             helper(curr+1,sz,nums,ans);
             swap(nums[i],nums[curr]);
         }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int sz=nums.size();
        sort(nums.begin(),nums.end());
        
        helper(0,sz,nums,ans);
        return ans;
    }
};