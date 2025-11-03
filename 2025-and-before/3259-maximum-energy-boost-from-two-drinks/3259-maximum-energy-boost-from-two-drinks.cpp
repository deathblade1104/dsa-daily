#include <vector>
#include <cstring>
using namespace std;

class Solution {
private:   
    int n;
    
//     long long helper(int curr, int currArr, vector<vector<int>>& arr) {
//         if (curr >= n)
//             return 0;
        
//         if (dp[curr][currArr] != -1)
//             return dp[curr][currArr];
        
//         // Option 1: Continue with the current array
//         long long op1 = arr[currArr][curr] + helper(curr + 1, currArr, arr);
        
//         // Option 2: Switch to the other array
//         long long op2 = helper(curr + 1, !currArr, arr);
        
//         return dp[curr][currArr] = max(op1, op2);
//     }
    
public:
    long long maxEnergyBoost(vector<int>& arr1, vector<int>& arr2) {
        // memset(dp, -1, sizeof(dp)); 
        n = arr1.size();
        // vector<vector<int>> arr = {arr1, arr2};
        // return max(helper(0, 0, arr), helper(0, 1, arr));
        
        vector<long long> prev(2, 0), curr(2, 0);

        // Fill the DP table from the end towards the start
        for (int i = n - 1; i >= 0; i--) {
            // Calculate current dp values
            curr[0] = max(arr1[i] + prev[0], prev[1]);
            curr[1] = max(arr2[i] + prev[1], prev[0]);

            // Move current values to previous for the next iteration
            prev = curr;
        }

        // The answer is the maximum of starting with either arr1 or arr2 at index 0
        return max(curr[0], curr[1]);
        
    }
};
