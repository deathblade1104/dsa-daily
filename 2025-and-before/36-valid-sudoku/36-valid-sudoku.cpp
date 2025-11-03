class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>>row(9,vector<bool>(10,false));
        vector<vector<bool>>col(9,vector<bool>(10,false));
        vector<vector<bool>>box(9,vector<bool>(10,false));
        
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