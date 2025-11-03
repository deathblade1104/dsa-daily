class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        
        int ending = points[0][1],ans = 1;
        
        for(int i=1;i<points.size();i++){
             if(points[i][0]>ending){
                 ans++;
                 ending = points[i][1];
             }
            
            else
            ending = min(ending,points[i][1]);
        }
        
        return ans;
    }
};