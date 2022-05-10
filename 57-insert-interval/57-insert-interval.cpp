class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>temp;
        bool flag = false;
        
        int i=0;
        
        while(i<intervals.size())
        {
            auto p = intervals[i];
            
            if(p[0]<=newInterval[0] or flag)
            {
                temp.push_back(p);
                i++;               
            }
            
            else
            {
                flag=true;
                temp.push_back(newInterval);
            }
        }
        
        if(!flag)
            temp.push_back(newInterval);
        
        intervals=temp;
        vector<vector<int>>ans;
        vector<int>prev = intervals[0];
        
        for(int i=1;i<intervals.size();i++)
        {
            vector<int>curr = intervals[i];
            if(prev[1]>=curr[0])
              prev[1]=max(curr[1],prev[1]);
            
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