//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &pairs) {
        // Write your code here.
        for(int i=0;i<pairs.size();i++){
            swap(pairs[i][0],pairs[i][1]);
            //pairs[i][2]+=pairs[i][0] - pairs[i][1];
        }
        
        sort(pairs.begin(),pairs.end());
        
        map<int,long long>dp;
        dp[0] = 0LL;
        
        for (auto& job : pairs) {
            long long cur = 1LL*job[2];
            cur+= prev(dp.upper_bound(job[1]))->second;
            
            //cout<<"Start Time is : "<<job[1]<<"  End Time is  : "<<job[0]<<"  And value is "<< job[2];
            //cout<<"   Prev value is : "<<prev(dp.upper_bound(job[1]))->second<< " from  : "<<prev(dp.upper_bound(job[1]))->first<<endl;
            
            if (cur > dp.rbegin()->second){
                dp[job[0]] = cur;
                //cout<<"Inserted for "<<job[0]<<endl;
            }
        }
        return dp.rbegin()->second;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends