typedef array<int, 2> arr;
typedef array<long long,2>arr2;

class Solution {
private:
    static const long long mod = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> ways(n, 0), dist(n, LLONG_MAX);
        vector<arr> adj[n];
       
        for (vector<int>& road : roads) {
            int u = road[0], v = road[1], d = road[2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        
        priority_queue<arr2, vector<arr2>, greater<arr2>> pq;
        pq.push({0, 0});
        ways[0] = 1; 
        dist[0] = 0;

        while (!pq.empty()) {
            arr2 curr = pq.top();
            pq.pop();
            long long currNode = curr[1], currDist = curr[0];
            
            if (currNode == n - 1) continue;
            
            for (arr& neigh : adj[currNode]) {
                int neighNode = neigh[0];
                long long neighDist = neigh[1]+ currDist;
                
                if (dist[neighNode] > neighDist) {
                    dist[neighNode] = neighDist;
                    ways[neighNode] = ways[currNode];
                    pq.push({neighDist,neighNode});
                } else if (dist[neighNode] == neighDist) {
                    ways[neighNode] = (ways[neighNode] + ways[currNode]) % mod;
                }
            }
        }
        
        return ways[n - 1];
    }
};
