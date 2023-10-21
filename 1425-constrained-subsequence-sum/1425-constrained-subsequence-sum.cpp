class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int m = nums.size();
        vector<int> dp(m, INT_MIN);
        priority_queue<pair<int, int>> pq;
        function<int(int)> DFS = [&](int i){
            //stop conditions
            if(i < 0) return 0;
            //memorization
            if(dp[i] != INT_MIN) return dp[i];

            int n = nums[i];
            //get max from max heap
            int maxJ = pq.size() ? pq.top().first : 0;
            if(maxJ >= 0) n += maxJ;
            //memorization
            return dp[i] = n;
        };

        int res = INT_MIN;
        for(int i = 0 ; i < m ; i++){
            //maintain max heap under index diff contraint
            while(pq.size() && i - pq.top().second > k) pq.pop();

            int val = DFS(i);
            res = max(res, val);
            //update max heap
            pq.push({val, i});
        }
        return res;
        
    }
};