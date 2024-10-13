class Solution {
public:
    typedef array<int, 4> arr; 
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<arr, vector<arr>, greater<arr>> pq; 
        vector<int>ans(2);
        
        int mini = INT_MAX, maxi = INT_MIN;
        
        
        for (int i = 0; i < n; i++) {
            int currSz = nums[i].size();
            pq.push({nums[i][0], 0, i,currSz});  
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
        }
        
        long long minRange = LLONG_MAX;
        
        // Process the heap
        while (pq.size() == n) { // Ensure we have at least one element from each vector
            auto p = pq.top();
            pq.pop();
            
            int currentMin = p[0];
            int indexInVector = p[1];
            int vectorIndex = p[2];
            int vectorSize = p[3];
            // Calculate the current range
            if (maxi - currentMin < minRange) {
                minRange = maxi - currentMin;
                ans = {currentMin, maxi};
            }
            
            // Move to the next element in the current vector
            if (indexInVector + 1 >= vectorSize) {
                break;
            }
            
            indexInVector++;
            int nextVal = nums[vectorIndex][indexInVector];
            pq.push({nextVal, indexInVector, vectorIndex,vectorSize});
            maxi = max(maxi, nextVal); 
           
        }
        
        return ans;
    }
};
