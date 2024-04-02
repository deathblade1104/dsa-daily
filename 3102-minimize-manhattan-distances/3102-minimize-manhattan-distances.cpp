class Solution {
public:
    
    array<int,2> getChebyshevDistance(vector<int>&point){
        return {point[0] + point[1], point[0] - point[1]};
    }
    
    
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int>st1,st2;
        
        for(vector<int>&point : points){
            array<int,2> arr = getChebyshevDistance(point);
            st1.insert(arr[0]);
            st2.insert(arr[1]);
        }
        
        int ans = INT_MAX;
        
        for(vector<int>&point : points){
            array<int,2> arr = getChebyshevDistance(point);
            st1.erase(st1.find(arr[0]));
            st2.erase(st2.find(arr[1]));
            
            int curr = max(*st1.rbegin() - *st1.begin(), *st2.rbegin() - *st2.begin());
            ans = min(ans, curr);
            
            st1.insert(arr[0]);
            st2.insert(arr[1]);
        }
        
        return ans;
    }
};