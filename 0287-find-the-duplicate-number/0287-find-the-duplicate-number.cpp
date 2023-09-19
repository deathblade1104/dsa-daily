class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            int val = nums[i];
            
            if(val<0)
                val*=-1;
            
            if(nums[val -1] <0)
                return val;
            
            nums[val -1]*=-1;
        }
        
        return 0;
        
    }
};