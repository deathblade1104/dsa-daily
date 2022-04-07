class NumMatrix {
public:
    int ps[201][201];
    NumMatrix(vector<vector<int>>& matrix) {
        memset(ps,0,201*201*sizeof(int));
        
        int n=matrix.size(), m=matrix[0].size();
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + matrix[i-1][j-1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        
        row1++;row2++;col2++;col1++;
        
        return ps[row2][col2] - ps[row2][col1-1] - ps[row1-1][col2] + ps[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */