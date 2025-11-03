class Solution {
public:
    bool isPossible(int&mid,vector<int>&nums, int&maxOperations)
    {
        int count =0;
        
        for(int&i : nums)
        {
            if(i<=mid)
                continue;
            
            else
                count+=((i-1)/mid);
        }
        
        return count<=maxOperations;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int max_ele = INT_MIN;
        for(int&i : nums)
            max_ele = max(i, max_ele);
        
        int low = 1,ans=0,high = max_ele;
        
        while(low<=high)
        {
            int mid = low + ((high - low)/2);
            
            if(isPossible(mid,nums,maxOperations))
            {
                ans = mid;
                high = mid -1;
            }
            
            else
            low = mid + 1;
        }
        
        return ans;
        
    }
};