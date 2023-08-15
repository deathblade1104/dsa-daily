class Solution {
public:
    
    
    void generateAllPossibleSubsetsOfAllSizes(int curr,int currSum,int currSz,int last,vector<int>arr[16],vector<int>&nums){
        
        if(curr>=last){
            arr[currSz].push_back(currSum);
            return;
        }
        
        generateAllPossibleSubsetsOfAllSizes(curr+1,currSum+nums[curr],currSz+1,last,arr,nums);
        generateAllPossibleSubsetsOfAllSizes(curr+1,currSum,currSz,last,arr,nums);
        
    }
    
    int minimumDifference(vector<int>& nums) {
        int N = nums.size(), n= N/2;
        
        vector<int>arr1[16],arr2[16];
        
        generateAllPossibleSubsetsOfAllSizes(0,0,0,n,arr1,nums);
        generateAllPossibleSubsetsOfAllSizes(n,0,0,N,arr2,nums);
        
        
        for(int i=0;i<16;i++){
            // sort(arr1[i].begin(),arr1[i].end());
            sort(arr2[i].begin(),arr2[i].end());
        }
        
        int totalSum  = 0, ans = INT_MAX;
        
        for(int&i : nums)
            totalSum+=i;
        
        int target = totalSum/2;
        
        for (int i = 0; i <= n; i++) {
            
            auto r = arr2[n - i];

            for (int curleftSum : arr1[i]) {
                int needSumFromRight = target - curleftSum;
                auto it = lower_bound(begin(r), end(r), needSumFromRight);
                if (it != end(r))
                    ans = min(ans, abs(totalSum - 2 * (curleftSum + *it)));
            }
        }
        
        return ans;
        
        
    }
};