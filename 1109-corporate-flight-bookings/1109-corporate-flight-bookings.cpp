class Solution {
public:
    int pref[20003];
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        memset(pref,0,sizeof pref);
        for(auto&v : bookings){
            pref[v[0]]+=v[2];
            pref[v[1]+1]-=v[2];
        }
        
        vector<int>ans;
        for(int i=1;i<=n;i++){
            pref[i]+=pref[i-1];
            ans.push_back(pref[i]);
        }    
        
        return ans;
        
    }
};