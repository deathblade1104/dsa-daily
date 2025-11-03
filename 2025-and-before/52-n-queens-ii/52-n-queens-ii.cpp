class Solution {
public:
    bool isValid(int i,int j, int&n, vector<vector<char>>&grid)
    {
        
        //Row check
        for(int k=0;k<n;k++)
        {
            if(grid[i][k]=='Q')
                return false;
        }
        
        //column check
        for(int k=0;k<n;k++)
        {
            if(grid[k][j]=='Q')
                return false;
        }
        
        //upper left diag check
        
        for(int k=1;k<=n;k++)
        {
            if(i-k<0 or j-k<0)
                break;
            
            if(grid[i-k][j-k]=='Q')
                return false;
        }
        
        //Upper right diag
        for(int k=1;k<=n;k++)
        {
            if(i-k<0 or j+k>=n)
                break;
            
            if(grid[i-k][j+k]=='Q')
                return false;
        }
        
        //lower left diag
        for(int k=1;k<=n;k++)
        {
            if(i+k>=n or j-k<0)
                break;
            
            if(grid[i+k][j-k]=='Q')
                return false;
        }
        
        //lower right diag
        
        for(int k=1;k<=n;k++)
        {
            if(i+k>=n or j+k>=n)
                break;
            
            if(grid[i+k][j+k]=='Q')
                return false;
        }
        
        return true;
    }
    
    void helper(int i,int&n,vector<vector<char>>&grid,int&ans)
    {
        if(i>=n)
        {
            ans++;   
            return;
        }
        
        for(int j=0;j<n;j++)
        {
            if(isValid(i,j,n,grid))
            {
                grid[i][j]='Q';
                helper(i+1,n,grid,ans);
                grid[i][j]='.';
            }
        }
        
        return;
        
    }
    
    int totalNQueens(int n) {
        
        int ans=0;
        vector<vector<char>>grid(n,vector<char>(n,'.'));    
        helper(0,n,grid,ans);
        return ans;
        
    }
};