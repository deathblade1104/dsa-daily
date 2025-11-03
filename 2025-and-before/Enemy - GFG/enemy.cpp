//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            
            unordered_set<int>rows,cols;
            
            for(auto v : enemy){
                rows.insert(v[0]);
                cols.insert(v[1]);
            }
            
            int maxRows=0,currRows=0,maxCols=0,currCols=0;
            
            for(int i=1;i<=n;i++){
                
                if(rows.count(i))
                currRows =0;
                
                else
                currRows++;
                
                maxRows = max(maxRows,currRows);
            }
            
            for(int i=1;i<=m;i++){
                
                if(cols.count(i))
                currCols =0;
                
                else
                currCols++;
                
                maxCols = max(maxCols,currCols);
            }
            
            
            return maxRows*maxCols;
            
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends