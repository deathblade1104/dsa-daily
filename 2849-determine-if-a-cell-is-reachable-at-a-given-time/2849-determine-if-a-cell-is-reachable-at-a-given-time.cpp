class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int maxDist = max(abs(sx-fx),abs(sy - fy));
        
        if(maxDist == 0 and t==1)
            return false;
        
        return t>=maxDist;
    }
};