class Solution {
public:
    void rotate_row(vector<int>&arr,int&n)
    {
        int low=0,high=n-1;
        
        while(low<high)
        {
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
        
        return;
    }
    
    void transpose(vector<vector<int>>&matrix,int &n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int  n = matrix.size();
        
        transpose(matrix,n);
        
        for(int i=0;i<n;i++)
            rotate_row(matrix[i],n);
        
        return;
        
    }
};