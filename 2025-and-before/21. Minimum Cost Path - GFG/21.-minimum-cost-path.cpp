// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    struct Node{
        int r, c,cost;
        
        Node(int x, int y, int z)
        {
            r=x;
            c=y;
            cost=z;
        }
    };
    
    struct mycomp{
        bool operator()(const Node&a, const Node&b)
        {
            return a.cost>b.cost;
        }
    };
    
    public:
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<int>dim={0,1,0,-1,0};
        
        priority_queue<Node, vector<Node>,mycomp>pq;
        Node temp(0,0,grid[0][0]);
        pq.push(temp);
        vis[0][0]=true;
        
        
        while(pq.size()>0)
        {
            Node t=pq.top();
            pq.pop();

            for(int i=1;i<5;i++)
            {
                int a=dim[i-1]+t.r,b=dim[i]+t.c;
                if(a>=0 and a<n and b>=0 and b<m and vis[a][b]==false)
                {   
                    if(a==n-1 and b==m-1)
                    return t.cost+grid[a][b];
                    
                    vis[a][b]=true;
                    
                    Node temp(a,b,t.cost+grid[a][b]);
                    pq.push(temp);
                }
            }
        }
        
        return -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends