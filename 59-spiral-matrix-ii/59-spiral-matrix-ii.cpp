class Solution {
public:
    void solve(int r1, int c1, int r2, int c2,int &val, vector<vector<int>>&ans)
    {
        if(r1>r2 or c1>c2)
            return;
        
        if(r1==r2 and c1==c2)
        {
            ans[r1][c1]=val;
            return;
        }
        
        for(int i=c1;i<=c2;i++)
            ans[r1][i]=val++;
        
        for(int i=r1+1;i<=r2;i++)
            ans[i][c2]=val++;        
        
        for(int i=c2-1;i>=c1;i--)
            ans[r2][i]=val++;
        
        for(int i=r2-1;i>r1;i--)
            ans[i][c1]=val++;
        
        solve(r1+1,c1+1,r2-1,c2-1,val,ans);
        return;      
        
        
    }
    
    
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>ans(n,vector<int>(n,-1));
        int val=1;
        solve(0,0,n-1,n-1,val,ans);
        
        return ans;
        

    }
};