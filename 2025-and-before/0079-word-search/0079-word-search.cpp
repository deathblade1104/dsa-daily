class Solution {
public:
    
    array<int,5>arr = {1,0,-1,0,1};
    bool wordsearch(int i, int j,int curr,string&word, vector<vector<char>>&grid)
    {
        if(curr>=word.size())
            return true;
        
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]!=word[curr])
            return false;        
        
        char ch = grid[i][j];
        grid[i][j]='.';
        
        for(int k=1;k<=4;k++)
        {
            bool op1 = wordsearch(i+arr[k-1],j+arr[k],curr+1,word,grid);
            if(op1) return true;
        }
            
        grid[i][j]=ch;
        return false;        
        
    }
    bool exist(vector<vector<char>>& grid, string word) {
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==word[0] and wordsearch(i,j,0,word,grid))
                    return true;
            }
        }
        
        return false;
    }
};