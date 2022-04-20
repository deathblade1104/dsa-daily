class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cz=0,p=1;
        
        for(int i : nums)
        {
            if(i ==0)
                cz++;
            
            else p*=i;
        }
        
        vector<int>ans(nums.size(),0);        
        if(cz<=1)
        {
            if(cz==1)
            {
                for(int i=0;i<nums.size();i++)
                {
                    if(nums[i]==0)
                        ans[i]=p;
                }
            }
            
            else if(cz==0)
            {
                for(int i=0;i<nums.size();i++)
                ans[i]=p/nums[i];
            }   
        }
        
        return ans;        
    
    }
};