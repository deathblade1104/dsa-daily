class Solution {
public:
    int check(vector<int>&nums,int&curr)
    {
        int count =0;
        
        for(int&i: nums)
        {
            if((i&curr)>0)
                count++;
        }
        
        return count;
    }
    
    int largestCombination(vector<int>& nums) {
        
        int max_ele = INT_MIN;
        
        for(int&i : nums)
            max_ele = max(max_ele ,i);
        
        int res=0, digits = floor(log2(max_ele)) + 1;
        
        for(int i=0;i<=digits;i++)
        {
            int curr = 1<<i;
            
            int temp = check(nums,curr);
            res = max(temp,res);
        }
        
        return res;
    }
};