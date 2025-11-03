class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        bool inc = true, dec = true;
        int n = nums.size();
        
        for(int i=1;i<n;i++){
            
            inc = inc & (nums[i]<=nums[i-1]);
            dec = dec & (nums[i]>=nums[i-1]);
            
            if(!inc and !dec)
                return false;
        }
        
        return true;
        
    }
};