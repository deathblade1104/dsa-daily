class Solution {
private:
    vector<vector<int>> ans;
    int n;
    
    void helper(int curr, int currSum, vector<int>& nums, vector<int>& temp) {
        if (currSum == 0) {
            ans.push_back(temp);
            return;
        }
        
        if (curr >= n || nums[curr] > currSum)
            return;
        
        for (int i = curr; i < n; i++) {
            
            if (nums[i] > currSum)
                break;
            
            if (i > curr && nums[i] == nums[i - 1])
                continue;
            
            temp.push_back(nums[i]);
            helper(i + 1, currSum - nums[i], nums, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates easily
        n = nums.size();
        ans.clear();
        vector<int> temp;
        helper(0, target, nums, temp);
        return ans;
    }
};
