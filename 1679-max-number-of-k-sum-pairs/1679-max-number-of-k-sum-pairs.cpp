class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());        
        int ans=0,l=0,h=nums.size()-1;
        
        while(l<h)
        {
            if(nums[l] + nums[h]==k)
            {
                ans++;
                l++;
                h--;
            }
            
            else if(nums[l] + nums[h] < k)
                l++;
            
            else h--;
        }
        
        return ans;        
    }
};