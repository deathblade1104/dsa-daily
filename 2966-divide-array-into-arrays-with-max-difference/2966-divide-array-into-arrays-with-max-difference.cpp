class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        
        for(int i=0;i<n;i+=3){
            if(nums[i+2] - nums[i]>k)
                return ans;
        }
        
        for(int i=0;i<n;i+=3){
            vector<int>curr;
            for(int j=0;j<3;j++){
                curr.push_back(nums[i+j]);
            }
            ans.push_back(curr);
        }
        
        return ans;
        
    }
};