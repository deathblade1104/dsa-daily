class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int z=0,o=0,ans=0,start=0,sz=nums.size();
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) z++;
            else o++;
            
            while(z>k and start<i)
            {
                if(nums[start]==0)
                    z--;
                
                else o--;

                start++;
            }
            
            ans=max(ans,o+k);
        }
        
        return min(ans,sz);
    }
};