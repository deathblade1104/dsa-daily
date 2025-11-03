class Solution {
public:
    
    int getDist(vector<int>&v1,vector<int>&v2){
        
        return max(abs(v1[0] - v2[0]), abs(v1[1] - v2[1]));    
    }
    
    
    int minTimeToVisitAllPoints(vector<vector<int>>& arr) {
        
        int ans = 0;
        
        for(int i=1;i<arr.size();i++){
            ans+=getDist(arr[i-1],arr[i]);
        }
        
        return ans;
        
    }
};