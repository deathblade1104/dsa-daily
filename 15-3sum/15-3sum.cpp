class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;         
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1,k=nums.size()-1;            
            
            while(j<k)
            {                
                if(nums[i] + nums[j] + nums[k] <0)
                    j++;
                
                else if(nums[i] + nums[j] + nums[k] > 0)
                    k--;
                
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    
                    int l = nums[j], r = nums[k];
                    
                    while(j<nums.size() and nums[j]==l)
                        j++;
                    
                    while(k>=0 and nums[k]==r)
                        k--;
                    
                }
            }
            
            int x = nums[i];
            while(i+1<nums.size() and nums[i+1]==x)
                i++;
        }
        
        return ans;
    }
};