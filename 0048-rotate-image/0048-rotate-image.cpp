class Solution {
public:
    
    int n;
    void transpose(vector<vector<int>>&mat){
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
    
    void reverseRows(vector<int>&arr){
        
        int i=0,j=n-1;
        
        while(i<j){
            swap(arr[i++],arr[j--]);
        }
        return;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        
        transpose(matrix);
        for(int i=0;i<n;i++)
            reverseRows(matrix[i]);
        return;
    }
       
};