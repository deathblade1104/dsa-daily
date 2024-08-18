#include <vector>
#include <cstring>
using namespace std;

class Solution {
private:
    static const int maxSz = 1e5 + 1;
    long long dp[maxSz][2];
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
        
        memset(dp, 0, sizeof(dp)); 
        
        // Fill the DP table from the end towards the start
        for (int i = n - 1; i >= 0; i--) {
            // If we choose arr1 at index i
            dp[i][0] = max(arr1[i] + dp[i + 1][0], dp[i + 1][1]);

            // If we choose arr2 at index i
            dp[i][1] = max(arr2[i] + dp[i + 1][1], dp[i + 1][0]);
        }
        
        // The answer is the maximum of starting with either arr1 or arr2 at index 0
        return max(dp[0][0], dp[0][1]);
    }
};
