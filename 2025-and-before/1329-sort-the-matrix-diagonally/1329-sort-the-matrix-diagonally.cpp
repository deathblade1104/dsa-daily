class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        for(int i=mat[0].size()-1;i>=0;i--)
        {
            vector<int>curr;
            int k=i,j=0;
            
            while(j<mat.size() and k<mat[0].size())
            {
                curr.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(curr.begin(),curr.end());
            k=i;
            j=0;
            int itr =0;
            
            while(j<mat.size() and k<mat[0].size())
            {
                mat[j][k]=curr[itr++];
                j++;
                k++;
            }           
        }
        
        for(int i=1;i<mat.size();i++)
        {
            vector<int>curr;
            int k=0,j=i;
            
            while(j<mat.size() and k<mat[0].size())
            {
                curr.push_back(mat[j][k]);
                j++;
                k++;
            }
            
            sort(curr.begin(),curr.end());
            k=0;
            j=i;
            int itr=0;
            
            while(j<mat.size() and k<mat[0].size())
            {
                mat[j][k]=curr[itr++];
                j++;
                k++;
            }     
        }
        
        return mat;
    }
};