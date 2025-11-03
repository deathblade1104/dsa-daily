// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int get_ans(int curr, int &sz,int sum,vector<int>&arr, unordered_map<string,int>&mp)
    {
        if(curr>=sz)
        {
            if(sum==0)
            return 1;
            
            return 0;
        }
        
        string key = to_string(curr) + "#" + to_string(sum);
        if(mp.count(key)==1)
        return mp[key];
        
        int plus=0,minus=0;
        plus=get_ans(curr+1,sz,sum+arr[curr],arr,mp);
        minus=get_ans(curr+1,sz,sum-arr[curr],arr,mp);
        mp[key]= plus + minus;
        return mp[key];
        
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        
        unordered_map<string,int>mp;
        int sz=A.size();
        
        return get_ans(0,sz,target,A,mp);
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends