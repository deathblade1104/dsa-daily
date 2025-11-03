class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {
        int n=arr.size();
        int temp[50001];
        
        temp[n-1]=arr[n-1]-n+1;
               
        for(int i=n-2;i>0;i--)
        temp[i] = max(temp[i+1],(arr[i]-i));
        
        int ans=INT_MIN;
        
        for(int i=0;i<n-1;i++)
        {
            int curr = arr[i] + i + temp[i+1];
            ans=max(ans,curr);
        }
        
        return ans;
        
        
    }
};