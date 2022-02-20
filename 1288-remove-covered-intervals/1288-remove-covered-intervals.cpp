class Solution {
public:
    static bool mycomp(vector<int>a,vector<int>b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        
        else return a[1]<b[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),mycomp);
        
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