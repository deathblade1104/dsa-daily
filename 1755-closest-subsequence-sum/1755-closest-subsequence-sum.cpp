class Solution {
public:
    void generateSubsetSums(int curr, int currSum, int&last,vector<int>&arr,vector<int>&nums){
        
        if(curr>=last){
            arr.push_back(currSum);
            return;
        }
        
        generateSubsetSums(curr+1,currSum+nums[curr],last,arr,nums);
        generateSubsetSums(curr+1,currSum,last,arr,nums);
        
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int N = nums.size(), n = N/2,ans = INT_MAX;
        vector<int>left,right;
        
        
        generateSubsetSums(0,0,n,left,nums);
        generateSubsetSums(n,0,N,right,nums);
        
        
        for(int& x : left)
            ans = min(ans, abs(x - goal));
        for(int& x : right)
            ans = min(ans, abs(x - goal));
        
        
        sort(begin(left), end(left));        
        sort(begin(right), end(right));
        
        int l = 0, r = right.size() - 1;
        
        while(l<left.size() && r>=0){
            int s = left[l] + right[r];
            ans = min(ans, abs(s - goal));
            if(s<goal) l++;
            else if(s>goal) r--;
            else break;
        }
        
        return ans;
        
    }
};