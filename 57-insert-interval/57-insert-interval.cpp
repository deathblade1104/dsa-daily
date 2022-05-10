class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>ans;
        bool flag = false;
        
        int i=0;        
        while(i<intervals.size())
        {
            auto p = intervals[i];
            
            if(p[0]<=newInterval[0] or flag)
            {
                ans.push_back(p);
                i++;               
            }
            
            else
            {
                flag=true;
                ans.push_back(newInterval);
            }
        }        
        if(!flag)
            ans.push_back(newInterval);
        
        intervals=ans;
        ans.clear();
        
        vector<int>prev = intervals[0];
        
        for(int i=1;i<intervals.size();i++)
        {
            if(prev[1]>=intervals[i][0])
              prev[1]=max(intervals[i][1],prev[1]);
            
            else
            {
                ans.push_back(prev);
                prev=intervals[i];
            }
        }
        
        ans.push_back(prev);
        
        return ans;
        
    }
};