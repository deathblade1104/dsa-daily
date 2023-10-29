class Solution {
public:
    
    vector<vector<int>>ans;
    int N;
    void helper(int currIdx, int currSum,vector<int>&nums,vector<int>&temp){
        
        if(currSum == 0){
            ans.push_back(temp);
            return;
        }
        
        
        if(nums[currIdx]<=currSum){
            temp.push_back(nums[currIdx]);
            helper(currIdx,currSum-nums[currIdx],nums,temp);
            temp.pop_back();
        }
        
        for(int j=currIdx+1;j<N;j++){
            if(nums[j]<=currSum and nums[j]!=nums[currIdx]){
                helper(j,currSum,nums,temp);
                break;
            }
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        ans.clear();
        vector<int>temp;
        sort(nums.begin(),nums.end());
        N = nums.size();
        
        helper(0,target,nums,temp);
        return ans;
    }
};