class Solution {
public:
    
    bool isValid(int&r,int&c, int&b,vector<vector<bool>>&row,vector<vector<bool>>&col,vector<vector<bool>>&box,int num)
    {
          if(row[r][num] or col[c][num] or box[b][num])
              return false;
        
        return true;
        
    }
    bool SudokuSolver(int r, int c,vector<vector<bool>>&row,vector<vector<bool>>&col,vector<vector<bool>>&box,vector<vector<char>>&board)
    {
        if(r>=9) return true;
        if(c>=9) return SudokuSolver(r+1,0,row,col,box,board);        
        if(board[r][c]!='.') return SudokuSolver(r,c+1,row,col,box,board);
        
        
        int b = ((r/3)*3) + (c/3);
        for(int i=1;i<=9;i++)
        {   
            if(isValid(r,c,b,row,col,box,i))
            {
                row[r][i] = col[c][i] = box[b][i] = true;
                board[r][c] = (char)(i + '0');

                if(SudokuSolver(r,c+1,row,col,box,board))
                    return true;
                
                row[r][i] = col[c][i] = box[b][i] = false;
                board[r][c] = '.';
            } 
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<bool>>row(9,vector<bool>(10,false));
        vector<vector<bool>>col(9,vector<bool>(10,false));
        vector<vector<bool>>box(9,vector<bool>(10,false));
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                
                int num = board[i][j]- '0';
                int b= ((i/3)*3) + (j/3);
                row[i][num] = col[j][num] = box[b][num] = true;
            }
        }
        
        bool ans = SudokuSolver(0,0,row,col,box,board);
        
        return;
    }
};