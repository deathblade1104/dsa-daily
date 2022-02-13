class Solution {
public:
    void get_ans(vector<int>&nums,int curr, int&n , vector<int>&temp,vector<vector<int>>&ans)
    {
        
        if(curr==n)
        {
            ans.push_back(temp);
            return;
        }
        
        
        get_ans(nums,curr+1,n,temp,ans);
        
        temp.push_back(nums[curr]);
        get_ans(nums,curr+1,n,temp,ans);
        temp.pop_back();
        
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        
        int n=nums.size();
        
        vector<int>t;
        get_ans(nums,0,n,t,ans);
        
        return ans;
    }
};