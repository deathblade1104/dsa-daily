class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int l=0,h=nums.size()-1,ans=0;
        while(l<h)
        {
            ans+=(nums[h]-nums[l]);
            l++;
            h--;
        }
        return ans;
        
        
        
    }
};