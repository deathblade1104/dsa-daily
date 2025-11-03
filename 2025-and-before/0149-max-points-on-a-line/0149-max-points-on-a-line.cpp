class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        // if there is only one point, the max points will be 1
        if( n == 1) return 1;
        // if there are more points, the max will be at least 2
        int maxAns = 1;
        unordered_map<double, int> tangentMap;
        for(int i=0; i<n-1; i++){
            tangentMap.clear();
            for(int j=0; j<n; j++){
                if(i == j)
                    continue;
                
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                // calculate the tangent..
                double tangent = atan2((y2-y1),(x2-x1));
                // increase the count..
                tangentMap[tangent]++;
                // calculate the max points from the tangentMap.
                // To include the point points[i] itself 
                // we added +1 to the values
                maxAns = max(maxAns, tangentMap[tangent]);
            }
        }
        
        return maxAns+1;
    }
};