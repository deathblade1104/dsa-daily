#include <vector>
#include <array>
#include <queue>
#include <climits>
using namespace std;

class Solution {
private:
    typedef array<int, 2> arr;

    struct myComp {
        bool operator()(const arr& a, const arr& b) {
            return a[1] >= b[1];
        }
    };

    vector<vector<arr>> createAdjList(vector<vector<int>>& edges, int n) {
        vector<vector<arr>> adjList(n);

        for (auto& edge : edges) {
            adjList[edge[0] - 1].push_back({edge[1] - 1, edge[2]});
        }

        return adjList;
    }

    int dijkstraTraversal(vector<vector<arr>>& adjList, int src, int n) {
        vector<int> vis(n, INT_MAX);
        priority_queue<arr, vector<arr>, myComp> pq;

        pq.push({src - 1, 0});
        while (!pq.empty()) {
            arr temp = pq.top();
            pq.pop();
            int curr = temp[0], dist = temp[1];

            if (vis[curr] <= dist) continue;

            vis[curr] = dist;

            for (auto& ngh : adjList[curr]) {
                int neighNode = ngh[0], neighDist = dist + ngh[1];
                if (vis[neighNode] > neighDist) {
                    pq.push({neighNode, neighDist});
                }
            }
        }

        int ans = 0;
        for (int i : vis) {
            if (i == INT_MAX) return -1; // Check if any node is not reachable
            ans = max(ans, i);
        }

        return ans;
    }

public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        
        if(edges.size()<n-1)
            return -1;
        
        vector<vector<arr>> adjList = createAdjList(edges, n);
        return dijkstraTraversal(adjList, k, n);
    }
};
