class Solution {
public:
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[ ]( const auto& lhs, const auto& rhs )
            {
                if(lhs[0] == rhs[0]) return lhs[1] > rhs[1];
                return lhs[0] < rhs[0];
            });
        
        int ans=0;
        vector<int>prev=intervals[0];
        
        for(int i=1;i<intervals.size();i++)
        {
            vector<int>curr=intervals[i];
            
            if(curr[0]<=prev[1] and curr[1]<=prev[1])
                ans++;
            
            else if(prev[0]==curr[0] and prev[1]<=curr[1])
            {
                ans++;
                prev=curr;
            }
            
            else prev=curr;
        }
        
        return intervals.size()-ans;
        
    }
};