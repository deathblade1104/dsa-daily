class Solution {
public:
    void helper(int pos, int&sz, vector<int>&nums, vector<vector<int>>&ans)
    {
         if (pos ==sz-1) {
            ans.push_back(nums);
             return;
        } 
        else 
        {
            for (int i = pos; i < sz; ++i) 
            {
                if (i > pos && nums[i] == nums[pos])
                    continue;
                
                swap(nums[pos], nums[i]);
                helper(pos + 1,sz,nums,ans);

            }
            
            for (int i = sz - 1; i > pos; --i) 
             swap(nums[pos], nums[i]);
        
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