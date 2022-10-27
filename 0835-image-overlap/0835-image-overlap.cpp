class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        vector<array<int,2>>v1,v2;
        
        int n = img1.size(), m = img1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(img1[i][j])
                    v1.push_back({i,j});
                
                if(img2[i][j])
                    v2.push_back({i,j});
            }
        }
        
        
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                
                int x = v1[i][0] - v2[j][0], y = v1[i][1] - v2[j][1];
                int temp = x*100 + y;
                
                mp[temp]++;
                
                ans = max(ans,mp[temp]);
            }
        }
        
        
        return ans;
    }
};