class Solution {
private : 
    vector<int>start,end;
    int n;
    
    void findMaxWindowSum(vector<int>&nums,int&windowSize,vector<int>&arr){
        
        int currSum = 0;
        
        for(int i=0;i<windowSize;i++){
            currSum+=nums[i];
        }
        
        arr[windowSize-1] = currSum;
        for(int i=windowSize;i<n;i++){
            currSum-=nums[i-windowSize];
            currSum+=nums[i];
            arr[i] = max(arr[i-1],currSum);
        }
        
        return;
        
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        
        if(f>s)
            swap(f,s);
        
        n = nums.size();
        start.assign(n,0);
        end.assign(n,0);
        
        findMaxWindowSum(nums,f,end);
        reverse(nums.begin(),nums.end());
        findMaxWindowSum(nums,f,start);
        reverse(start.begin(),start.end());
        reverse(nums.begin(),nums.end());
        

        int currSum = 0;

        for(int i=0;i<s;i++){
            currSum+=nums[i];
        }
        
        int ans = currSum + start[s];
        
        for(int i=s;i<n;i++){
            currSum-=nums[i-s];
            currSum+=nums[i];
            
            int startSum = i+1<n ? start[i+1] :0;
            int endSum = i-s-1>=0? end[i-s-1] :0;
            
            ans  = max(ans,currSum + max(startSum,endSum));
            
            
        }
        
        return ans;
    }
};