class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int sz) {
        
        sort(tiles.begin(), tiles.end());
        
        int ans=0,j=0,i=0,cover=0;
        
        while(i<tiles.size() and ans<sz)
        {
            if(tiles[j][0] + sz > tiles[i][1])
            {
                cover+= (tiles[i][1] - tiles[i][0] + 1);
                ans = max(ans,cover);
                i++;
            }
            
            else
            {
                int part = tiles[j][0] + sz - tiles[i][0];
                ans = max(ans,cover+part);
                cover-= (tiles[j][1] - tiles[j][0] +1);
                j++;
            }
        }
        
        return ans;
        
        
    }
};