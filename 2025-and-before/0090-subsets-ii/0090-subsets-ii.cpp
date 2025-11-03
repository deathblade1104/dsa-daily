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
        
        int idx = N;
        for(int j=curr+1;j<N;j++){
            if(nums[j] != nums[curr]){
                idx = j;
                break;
            }
            
        }
        helper(idx,temp,nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        vector<int>temp;
        sort(nums.begin(),nums.end());
        N = nums.size();
        helper(0,temp,nums);
        return ans;
    }
};