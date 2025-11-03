class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        int pos,neg;
        
        pos=nums.size(),neg-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                pos = i;
                break;
            }
            neg=i;
        }
        
        if(pos!= nums.size())
        neg = pos - 1;
        
        while(neg>=0 and pos<nums.size())
        {
            if(abs(nums[neg])<=nums[pos])
            {
                ans.push_back(nums[neg]* nums[neg]);
                neg--;
            }
            
            else
            {                
                ans.push_back(nums[pos]* nums[pos]);
                pos++;
            }
        }
        
        while(neg>=0)
        {
            ans.push_back(nums[neg]* nums[neg]);
            neg--;
        }
        
        while(pos<nums.size())
        {
             ans.push_back(nums[pos]* nums[pos]);
             pos++;
        }
        
        return ans;
    }
};