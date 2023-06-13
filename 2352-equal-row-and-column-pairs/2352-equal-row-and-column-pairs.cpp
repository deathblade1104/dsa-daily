class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        unordered_map<string,int>mp;
        int ans = 0,m = grid.size(),n = grid[0].size();
        
        for(int i=0;i<m;i++){
            string temp = "";
            for(int j=0;j<n;j++){
                temp+=to_string(grid[i][j]);
                temp+="_";
            }
            mp[temp]++;
        }
        
        for(int i=0;i<n;i++){
            string temp = "";
            for(int j=0;j<m;j++){
                temp+=to_string(grid[j][i]);
                temp+="_";
            }
            ans+=mp[temp];
        }
        
        return ans;
        
        
    }
};