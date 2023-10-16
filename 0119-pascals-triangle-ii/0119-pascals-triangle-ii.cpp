class Solution {
public:
    vector<int> getRow(int ri) {
        vector<vector<int>>ans(ri+1);        
        ans[0]={1};
        
        for(int i=1;i<=ri;i++)
        {
            vector<int>temp(i+1,1);
            
            for(int j=1;j<i;j++)
            temp[j] = ans[i-1][j-1] + ans[i-1][j];
            
            ans[i]=temp;
        }
        
        
        return ans[ri];
    }
};