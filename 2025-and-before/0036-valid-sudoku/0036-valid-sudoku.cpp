class Solution {
public:
    
    bool row[9][10],col[9][10],box[9][10];
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(row,0,sizeof row);
        memset(col,0,sizeof col);
        memset(box,0,sizeof box);
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                
                int num = board[i][j] - '0';
                int box_c = ((i/3)*3) + (j/3);
                
                if(row[i][num] or col[j][num] or box[box_c][num])
                    return false;
                
                row[i][num]=col[j][num]=box[box_c][num]=true;
            }
        }
        
        return true;
    }
};