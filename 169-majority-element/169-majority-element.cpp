class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=1,me=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(freq==0)
                me=nums[i];
            
            if(me!=nums[i])
                freq--;
            
            else freq++;
        }
        
        return me;
        
    }
};