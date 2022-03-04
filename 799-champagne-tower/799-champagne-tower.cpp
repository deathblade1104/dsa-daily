class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
         double glasses [101] [101] = {0.0};

        glasses[0][0] = poured;

        for(int i = 0;i<=query_row; i++) 
        {
            for(int j = 0; j <=i;j++)
            {
                if(glasses[i][j] > 1)
                {
                    double rem = glasses[i][j] - 1;
                    glasses [i][j] = 1;
                    glasses [i+1][j] += rem/2;
                    glasses [i+1][j+1] += rem/2;
                }
            }
        }
                                      
        return glasses [query_row][query_glass];
        
        
        
        
    }
};