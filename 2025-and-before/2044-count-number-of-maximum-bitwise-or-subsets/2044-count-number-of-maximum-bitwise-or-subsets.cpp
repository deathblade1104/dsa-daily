class Solution {
public:
    
    int backtrack(int idx, int curr_val,int&check,vector<int>&nums)
    {
        if(idx>=nums.size())
            return 0;
        
        int res=0, temp = curr_val|nums[idx];
        
        if(temp == check)
            res++;
        
        res+=backtrack(idx+1,temp,check,nums);
        res+=backtrack(idx+1,curr_val,check,nums);
        
        return res;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        
        int check=0;

        for(int &i: nums)
            check = check|i;
        
        return backtrack(0,0,check,nums);
        
    }
};