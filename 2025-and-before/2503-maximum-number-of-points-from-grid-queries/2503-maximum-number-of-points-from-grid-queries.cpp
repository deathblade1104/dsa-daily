class Solution {
public:
    typedef array<int, 2> arr;
    typedef array<int, 3> arr2;

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int q = queries.size(), n = grid.size(), m = grid[0].size();
        int dir[5] = {1, 0, -1, 0, 1};

        vector<arr> temp;
        vector<int> ans(q, 0);

        for (int i = 0; i < q; i++) {
            temp.push_back({queries[i], i});
        }

        sort(temp.begin(), temp.end());

        priority_queue<arr2, vector<arr2>, greater<arr2>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        int counter = 0;

        for(int i=0;i<q;i++){
                
            while(pq.size()){
                arr2 curr = pq.top();
                
                if(temp[i][0]<=curr[0])
                    break;
                
                pq.pop();
                counter++;

                int r = curr[1], c = curr[2];
                for (int k = 1; k <= 4; k++) {
                    int x = r + dir[k - 1], y = c + dir[k];

                    if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y])
                        continue;

                    pq.push({grid[x][y], x, y});
                    vis[x][y] = true;
                }
            }
        
            ans[temp[i][1]] = counter;
        
        }
       

        return ans;
    }
};
