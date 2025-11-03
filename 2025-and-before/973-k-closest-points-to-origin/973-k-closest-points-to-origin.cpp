class Solution {
public:
    struct mycomp{
        bool operator()(const vector<int>&a, const vector<int>&b)
        {
            return ((a[0]*a[0]) + (a[1]*a[1])) < ((b[0]*b[0]) + (b[1]*b[1]));
        }
    };
        
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<int>, vector<vector<int>> , mycomp>pq;
        
        for(auto i : points)
        {
            pq.push({i[0],i[1]});
            
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<vector<int>>ans;
        while(pq.size()>0)
        {
            auto p = pq.top(); pq.pop();
            ans.push_back({p[0],p[1]});
        }
        
        return ans;
        
        
    }
};