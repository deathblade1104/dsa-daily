//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
   void solve(int r1, int c1, int r2, int c2,vector<int>&ans,vector<vector<int>>&grid)
    {
        if(r1>r2 or c1>c2)
            return;
        
        for(int i=c1;i<=c2;i++)
            ans.push_back(grid[r1][i]);
        
        r1++;
        
        for(int i=r1;i<=r2;i++)
            ans.push_back(grid[i][c2]);        
        
        c2--;
        
        for(int i=c2;i>=c1;i--)
          if (r1 <= r2)
            ans.push_back(grid[r2][i]);
            
        r2--;
       
        for(int i=r2;i>=r1;i--)
            if(c1<=c2)
                ans.push_back(grid[i][c1]);
        
        c1++;
                    
        solve(r1,c1,r2,c2,ans,grid);
        return;      
    }
    
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        
        vector<int>ans;
        solve(0,0,R-1,C-1,ans,a);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends