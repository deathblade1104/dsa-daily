class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>LIS(n,1),count(n,1);
        int max_LIS=-1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(LIS[i] < LIS[j] + 1)
                    {
                        LIS[i] = LIS[j] + 1;
                        count[i] = count[j];
                    }
                    
                    else if (LIS[i] == LIS[j] + 1)
                    {
                        count[i] += count[j];
                    }
                }
            }
            
            max_LIS = max(max_LIS,LIS[i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(LIS[i] == max_LIS)
                ans+= count[i];
        }

        return ans;
    }
    
    
};