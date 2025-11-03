class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size(), c = board[0].size();
        vector<vector<int>>ans(r, vector<int>(c,0));
        int dim[]={-1,0,1,0,-1,-1,1,1,-1};
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int count =0;
                for(int k=1;k<9;k++)
                {
                    int x= i + dim[k-1];
                    int y = j + dim[k];
                    
                    if(x>=0 and y>=0 and x<r and y<c and board[x][y]==1)
                        count++;
                }                
                if((board[i][j] == 1 and count>=2 and count<=3) or count ==3)
                    ans[i][j]=1;    
            }
        }
        
        board=ans;
        
    }
};