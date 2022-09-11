class Solution {
public:
    int arr[100001];
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        memset(arr,0, sizeof arr);
        
        for(auto&curr : bookings){
            arr[curr[0]]+=curr[2];
            arr[curr[1]+1]-=curr[2];
        }
        
        vector<int>ans;
        
        for(int i=1;i<=n;i++){
            
            arr[i]+=arr[i-1];
            ans.push_back(arr[i]);
        }    
        
        return ans;
    }
};