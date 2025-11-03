class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>inedges(numCourses,0);
        vector<vector<int>>adj(numCourses);
        
        for(auto&v : prerequisites)
        {
            inedges[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        
        queue<int>q;
        vector<int>ans;
        vector<int>temp;
        for(int i=0;i<numCourses ;i++)
        {
            if(inedges[i]==0)
                q.push(i);
        }
        
        if(q.size()==0)
            return temp;
        
        while(q.size()>0)
        {
            auto p = q.front();
            q.pop();
            
            ans.push_back(p);
            
            for(auto&neigh : adj[p])
            {
                inedges[neigh]--;
                
                if(inedges[neigh]==0)
                    q.push(neigh);
            }
        }
        
        
        
        return ans.size()==numCourses? ans : temp;
        
    }
};