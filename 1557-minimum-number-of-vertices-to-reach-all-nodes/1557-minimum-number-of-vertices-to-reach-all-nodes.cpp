class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>inEdge(n,0);        
        for( auto p : edges)
        inEdge[p[1]]++;
        
        
        vector<int>ans;
        for(int i=0;i<n;i++)
            if(inEdge[i]==0)
                ans.push_back(i);
        
        return ans;
        
    }
};