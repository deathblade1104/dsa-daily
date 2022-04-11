class Solution {
public:
    pair<int,int> get_dimension(int ele , int&n, int&m)
    {
        int r=ele/m, c=ele%m;
        if(m==1) r=ele;
        if(n==1) c=ele;
        
        pair<int,int>p=make_pair(r,c);
        return p;
        
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int r= grid.size(), c= grid[0].size();
        k = k%(r*c);
        
        if(k==0)return grid;      
        vector<vector<int>>ans(r,vector<int>(c));
        
        int e_org=0,e=0;
        
        while(e_org < ((r*c)-k))
        {            
            auto p1 = get_dimension(e_org, r,c);
            auto p2 = get_dimension(e_org+k,r,c);
            
            ans[p2.first][p2.second] = grid[p1.first][p1.second];           
            e_org++;
        }
        
        while(e_org<(r*c))
        {
            auto p1 = get_dimension(e_org, r,c);
            auto p2 = get_dimension(e,r,c);
            
            ans[p2.first][p2.second] = grid[p1.first][p1.second];
            e++;
            e_org++;
        }
        
        return ans;
        
    }
};