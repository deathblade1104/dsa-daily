class NumMatrix {
public:
    vector<vector<int>>grid;
    NumMatrix(vector<vector<int>>& matrix) {
        int n= matrix.size(), m = matrix[0].size();
        vector<vector<int>>temp(n+1, vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
            for(int j =1;j<=m;j++)
                temp[i][j] = temp[i-1][j] + temp[i][j-1] - temp[i-1][j-1] + matrix[i-1][j-1];
        
        grid = temp;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        row1++;
        row2++;
        col1++;
        col2++;
        
        return grid[row2][col2] - grid[row2][col1-1] - grid[row1-1][col2] + grid[row1-1][col1-1];
    }
};

class Solution {
public:
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        NumMatrix obj = NumMatrix(matrix);
        
        int n= matrix.size(),m = matrix[0].size(),ans = 0;
        
        for(int r1=0;r1<n;r1++){
            for(int c1=0;c1<m;c1++){
                for(int r2=r1;r2<n;r2++){
                    for(int c2=c1;c2<m;c2++){
                        int currSum = obj.sumRegion(r1,c1,r2,c2);
                        //cout<<r1<<" : "<<c1<<" : "<<r2<<" : "<<c2<<" == "<<currSum<<endl;
                        
                        if(currSum == target)
                            ans++;
                    }
                }
            }
        }
        
        return ans;
        
        
    }
};