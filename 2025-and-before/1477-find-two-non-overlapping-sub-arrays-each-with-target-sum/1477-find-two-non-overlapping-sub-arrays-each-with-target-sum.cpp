class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int>arr(n,n+1);
        int currSum = 0, start = 0,ans = n+1;
        
        for(int i=0;i<n;i++){
            
            currSum+=nums[i];
            
            while(currSum>target){
                currSum-=nums[start++];
            }
            
            int currSize = n+1,prevEnd = i-1>=0 ? arr[i-1] : n+1;
            if(currSum == target){
                
                currSize = i - start + 1;
                int prev = start-1>=0 ? arr[start -1] : n+1;
                
                ans = min(ans, prev + currSize);
                
            }
            arr[i] = min(currSize,prevEnd);
            //cout<<i<<" "<<currSize<<" "<<prevEnd<<" "<<arr[i]<<endl;
            
        }
        
        
        
        return ans>n? -1 : ans;
        
    }
};