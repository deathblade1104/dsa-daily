class NumMatrix {
    private:
    vector<vector<int>>ps;

    public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>p(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                p[i][j] = matrix[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
        ps=p;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row2+=1;
        row1+=1;
        col1+=1;
        col2+=1;
        
        
        return ps[row2][col2] +ps[row1-1][col1-1] - ps[row2][col1-1] - ps[row1-1][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */