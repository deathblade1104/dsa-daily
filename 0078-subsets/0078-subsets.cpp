class Solution {
public:
    vector<vector<int>>ans;
    
    int N;
    
    void helper(int curr,vector<int>&temp,vector<int>&nums){
        
        if(curr>=N){
            ans.push_back(temp);
            return;
        }
    
        temp.push_back(nums[curr]);
        helper(curr+1,temp,nums);
        temp.pop_back();
        
        
        helper(curr+1,temp,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        vector<int>temp;
        N = nums.size();
        helper(0,temp,nums);
        return ans;
        
    }
};