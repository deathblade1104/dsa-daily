class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<int>highest;
        int second_highest = INT_MIN,n = nums.size()-1;
        
        for(int i=n;i>=0;i--)
        {            
            if(nums[i]<second_highest)
                return true;
            
            while(highest.size()!=0 and highest.top()<nums[i])
            {
                second_highest = highest.top();
                highest.pop();
            }
            
            highest.push(nums[i]);
        }
        
        return false;
        
    }
};