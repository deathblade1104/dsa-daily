class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        
        vector<int>nums=arr;
        
        sort(nums.begin(),nums.end());
        
        int i=0,j=nums.size()-1;
                
        while(i<=j)
        {
            if(nums[i]==arr[i])
                i++;
            
            if(nums[j]==arr[j])
                j--;
            
            else if(nums[i]!=arr[i] and nums[j]!=arr[j])
                break;
        }
        
        if(i>=j)
            return 0;
        
        return (j-i+1);
        
    }
};