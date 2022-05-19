class Solution {
public:
    
    void reverse(vector<int>&nums, int l , int h)
    {
        while(l<h)
        {
            swap(nums[l],nums[h]);
            l++;
            h--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        
        int sz = nums.size();
        k=k%sz;        
        if(k==0)
            return;
        
        
        reverse(nums,0,sz-1-k);
        reverse(nums,sz-k,sz-1);
        reverse(nums,0,sz-1);
        
        return;
        
        
        
    }
};