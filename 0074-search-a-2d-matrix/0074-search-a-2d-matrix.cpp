class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int rows = mat.size(),cols = mat[0].size(), sz = rows * cols, high = sz -1 , low = 0;
        
        while(low<=high){
            int mid = low + ((high - low )/2);
            int currRow = mid/cols, currCol = mid%cols;
            
            if(mat[currRow][currCol] == target)
                return true;
            
            else if(mat[currRow][currCol] > target)
                high = mid - 1;
            
            else low = mid +1 ;
                
        }
        
        return false;
        
    }
};