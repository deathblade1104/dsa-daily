class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string>ans;
        
        if(nums.size()==0)
            return ans;
        
        string curr="";
        curr+=to_string(nums[0]);
        int count=1;
        
        for(int i=1;i<nums.size();i++)
        {
            
            if(1 + nums[i-1] == nums[i])
                count++;
            
            else
            {
                if(count==1)
                    ans.push_back(curr);
                
                
                else
                {
                    curr+="->" + to_string(nums[i-1]);      
                    ans.push_back(curr);                                   
                }
                
                curr=to_string(nums[i]);
                count=1;
            }            
        }
        
        if(count>=2)
           curr+="->" + to_string(nums[nums.size()-1]);
        
        ans.push_back(curr);
        
        return ans;
        
        
        
        
        
    }
};