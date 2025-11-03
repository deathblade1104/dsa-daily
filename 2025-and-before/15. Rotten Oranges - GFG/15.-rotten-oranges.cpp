// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    private:
    struct Node{
        int r,c,times;
        
        Node(int a, int b, int x)
        {
            r=a;
            c=b;
            times=x;
        }
    };
    
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),count=0;
        queue<Node>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    Node temp(i,j,0);
                    q.push(temp);
                }
                
                else if(grid[i][j]==1)
                count++;
            }
        }
        
        if(q.size()==0 and count!=0)
        return -1;
        
        int ans=INT_MIN;
        while(q.size()>0 and count>0)
        {
            Node t = q.front();
            q.pop();
            
            if(t.r<0 or t.r>=n or t.c<0 or t.c>=m or grid[t.r][t.c]==0)
            continue;
            
            if(grid[t.r][t.c]==1)
            count--;
    
            grid[t.r][t.c]=0;
            ans=max(ans,t.times);
            
            Node t1(t.r+1,t.c,t.times+1);
            Node t2(t.r-1,t.c,t.times+1);
            Node t3(t.r,t.c+1,t.times+1);
            Node t4(t.r,t.c-1,t.times+1);
            
            q.push(t1);
            q.push(t2);
            q.push(t3);
            q.push(t4);
        }
        
        if(count!=0)
        return -1;
        
        return ans;
        
        
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends