class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(),events.end());
        
        int m =-1,res =0,j=0;
        
        for(auto&v : events)
            m = max(m,v[1]);
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        
        for(int i=events.front()[0];i<=m;i++){
            
            while(j<events.size() and events[j][0]==i)
                pq.push(events[j++][1]);
            
            while(pq.size() and pq.top()<i)
                pq.pop();
            
            if(pq.size()){
                res++;
                pq.pop();
            }
            
            if(pq.empty()&&j==pq.size())
                break;
        }
        
        return res;
        
        
    }
};