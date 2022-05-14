class Solution {
public:
    void helper(int curr, int&sz, vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans,bool consider)
    {
        if(curr>=sz)
        {
            ans.push_back(temp);
            return;
        }
        
        helper(curr+1,sz,nums,temp,ans,false);
        
        if(curr>0 and nums[curr]==nums[curr-1] and consider==false)
            return;
        
        temp.push_back(nums[curr]);
        helper(curr+1,sz,nums,temp,ans,true);
        temp.pop_back();
        
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int sz=nums.size();
        vector<int>temp;
        vector<vector<int>>ans;
        
        helper(0,sz,nums,temp,ans,false);
        return ans;
    }
};