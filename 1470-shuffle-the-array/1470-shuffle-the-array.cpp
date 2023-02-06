class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int>ans(2*n);
        int j=0;
        for(int i=0;i<n;i++){
            
            ans[j++] = nums[i];
            ans[j++] = nums[i+n];
        }
        
        return ans;
    }
};