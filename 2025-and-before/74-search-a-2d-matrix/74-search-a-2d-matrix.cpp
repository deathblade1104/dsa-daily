class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m=matrix[0].size();
        int start=0, end =(n*m)-1;
        
        while(start<=end)
        {
            int mid = start + ((end-start)/2);
            int cr=mid/m,cc=mid%m;
            
            if(matrix[cr][cc]==target)
                return true;
            
            else if (matrix[cr][cc]<target)
                start=mid+1;
            
            else
                end=mid-1;               
            
        }
        return false;
    }

};