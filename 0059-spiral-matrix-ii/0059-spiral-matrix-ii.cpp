class Solution {
public:
    int r1,c1,r2,c2;
    
    void spiralTraverse(int&num,vector<vector<int>>&ans){
        
        if(r1>r2 || c1>c2)
            return;
        
        for(int i=c1;i<=c2;i++)
            ans[r1][i] = num++;
        
        r1++;
        
        for(int i=r1;i<=r2;i++)
            ans[i][c2] = num++;
        
        c2--;
        
        for(int i=c2;i>=c1;i--)
            ans[r2][i] = num++;
        
        r2--;
        
        for(int i=r2;i>=r1;i--)
            ans[i][c1] = num++;
        
        c1++;
        
        spiralTraverse(num,ans);
        return;
    }
    vector<vector<int>> generateMatrix(int n) {
        
        r1=c1=0;
        r2 = c2 = n-1;
        vector<vector<int>>ans(n,vector<int>(n,-1));
        int num = 1;
        
        spiralTraverse(num,ans);
        
        return ans;
        
        
    }
};