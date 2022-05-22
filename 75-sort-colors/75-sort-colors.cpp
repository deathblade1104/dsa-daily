class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int cz,co,ct;
        cz=co=ct=0;
        
        for(int&i : nums)
        {
            if(i==0)
                cz++;
            
            else if(i==1)
                co++;
            
            else ct++;
        }
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(cz>0)
            {
                nums[i]=0;
                cz--;
            }
            
            else if(co>0)
            {
                nums[i]=1;
                co--;
            }
            
            else if(ct>0)
            {
                nums[i]=2;
                ct--;
            }
        }
        
        return;
    }
};