class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            
            int x = abs(nums[i]) - 1;
            
            if(nums[x]<0)
                ans.push_back(x+1);
                
            else nums[x] = - nums[x];
            
        }
        
        return ans;
    }
};