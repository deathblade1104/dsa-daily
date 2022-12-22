class Solution {
private:
    vector<vector<int>> adj_list;
    vector<int> ans, count;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj_list.resize(n);
        ans.assign(n, 0);
        count.assign(n, 1);
        for (int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        post_order_dfs(0, -1);
        pre_order_dfs(0, -1);
        return ans;
    }

private:
    void post_order_dfs(int root, int prev) {
        for (int node : adj_list[root]) {
            if (node == prev) continue;
            post_order_dfs(node, root);
            count[root] += count[node];
            ans[root] += ans[node] + count[node];
        }
    }

    void pre_order_dfs(int root, int prev) {
        for (int node : adj_list[root]) {
            if (node == prev) continue;
            ans[node] = ans[root] - count[node] + (count.size() - count[node]);
            pre_order_dfs(node, root);
        }
    }
};