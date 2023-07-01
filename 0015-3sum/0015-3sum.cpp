class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
         for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;            
            
            while(j<k)
            {                
                if(nums[i] + nums[j] + nums[k] <0){
                    j++;
                }
                
                else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    
                    int l = nums[j], r= nums[k];
                    
                    while(j<n and j<k and nums[j]==l)
                        j++;
                    
                    while(k>=0 and k>j and nums[k]==r)
                        k--;
                    
                }
            }

            while(i+1<n and nums[i+1]==nums[i])
                i++;
        }
        
        return ans;
    }
};