class Solution {
public:
    struct  mycomp
    {
        bool operator()(const vector<int>&a, const vector<int>&b)
        {
            if(a[0]!=b[0])
                return a[0]<b[0];
            
            return a[1]<b[1];
            
        }
    };
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),mycomp());
        
        vector<vector<int>>ans;
        vector<int>prev = intervals[0];
        
        for(int i=1;i<intervals.size();i++)
        {
            vector<int>curr = intervals[i];
            if(prev[1]>=curr[0])
            {
                prev[1]=max(curr[1],prev[1]);
                // prev[0]=min(curr[0],prev[0]);
            }
            
            else
            {
                ans.push_back(prev);
                prev=curr;
            }
        }
        
        ans.push_back(prev);
        
        return ans;
    }
};