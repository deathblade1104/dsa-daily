class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size(),r = 0, c =m-1;
        
        while(c>=0 and r<n){
            
            if(matrix[r][c] == target)
                return true;
            else if (matrix[r][c]>target)
                c--;
            else r++;
        }
        
        return false;
        
    }
};