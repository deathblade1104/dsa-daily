class Solution {
public:
    int n,avg;
    vector<int>nums;
    static const int maxN=16,finalState = (1<<maxN) -1;
    int dp[finalState][maxN+1];
    
    int getSum(int mask){
    
        int sum = 0;
        
        for(int i=0;i<n;i++){
            if(mask & (1<<i))
                sum+=nums[i];
        }
        
        return sum;
    }
    
bool helper(int mask, int parts) {
    int curr = __builtin_popcount(mask);

    if (curr >= n)
        return parts == 0;

    if (parts < 0)
        return false;

    int &ans = dp[mask][parts];

    if (ans != -1)
        return ans;

    ans = 0;

    int currSum = getSum(mask)%avg;

    for (int i = 0; i < n; i++) {
        if (mask & (1 << i))
            continue;

        int newMask = mask | (1 << i);

        if (currSum + nums[i] <= avg)
            ans = ans || helper(newMask, parts);

        if (currSum + nums[i] == avg)
            ans = ans || helper(newMask, parts - 1);
    }

    return ans;
}

    
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        n=arr.size();
        nums = arr;
        
        int sum=0,maxi=0;
        
        for(int&i : arr){
            sum+=i;
            maxi= max(maxi,i);
        }
        
        avg = sum/k;
        
        if(n<k or (sum%k) or maxi>avg)
            return false;
        
        
        memset(dp,-1,sizeof dp);
        return helper(0,k);
        
    }
};