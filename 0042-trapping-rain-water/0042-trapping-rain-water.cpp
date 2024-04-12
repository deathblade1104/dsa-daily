class Solution {
public:
    int trap(vector<int>&  arr) {
        int n = arr.size();
        vector<int>low(n),high(n);
        low[0] = arr[0];
        high[n-1] = arr[n-1];
            
        for(int i=1;i<n;i++)
         low[i]=max(low[i-1],arr[i]);
        
        for(int i=n-2;i>=0;i--)
            high[i]=max(high[i+1],arr[i]);
        
        int ans=0;
        for(int i=1;i<=n-2;i++)
        ans+=(min(low[i],high[i]) - arr[i]);
        
              return ans;
    }
};