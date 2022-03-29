class Solution {
public:
    vector<vector<int>> generate(int nr) {
        vector<vector<int>>ans(nr);        
        ans[0]={1};
        
        if(nr==1)
            return ans;
        
        for(int i=1;i<nr;i++)
        {
            vector<int>temp(i+1,1);
            
            for(int j=1;j<i;j++)
            temp[j] = ans[i-1][j-1] + ans[i-1][j];
            
            ans[i]=temp;
        }
        
        
        return ans;
        
    }
};