class Solution {
private: 
    int n, k, finalState;
    vector<vector<int>> dp;
    vector<int> subsetSum;
    
    int helper(int currWorker, int currState, vector<int>& jobs) {
        if (currWorker == k && currState == finalState) {
            return 0;
        }
        
        if (currState == finalState || currWorker == k)
            return INT_MAX / 2;  // Return a large value since this is not a valid state
        
        if (dp[currWorker][currState] != -1)
            return dp[currWorker][currState];
        
        int ans = INT_MAX / 2;

        // Try to assign jobs to the current worker using all available subsets of jobs
        for (int subset = 1; subset <= finalState; subset++) {
            // Ensure that no job in the current subset is already assigned (i.e., check overlap)
            if ((subset & currState) != 0)
                continue;
            
            int newState = subset | currState;
            ans = min(ans, max(subsetSum[subset], helper(currWorker + 1, newState, jobs)));
        }

        return dp[currWorker][currState] = ans;
    }
    
public:    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        n = jobs.size();
        this->k = k;
        finalState = (1 << n) - 1;  // Represents all jobs being assigned
        
        // DP initialization: k workers, state of job assignment (finalState)
        dp.assign(k + 1, vector<int>(finalState + 1, -1));
        subsetSum.assign(finalState + 1, 0);
        
        // Compute subset sums: the sum of job times for each subset of jobs
        for (int subset = 1; subset <= finalState; subset++) {
            for (int j = 0; j < n; j++) {
                if ((subset & (1 << j)) != 0) {
                    subsetSum[subset] += jobs[j];
                }
            }
        }
        
        return helper(0, 0, jobs);
    }
};
