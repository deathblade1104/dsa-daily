// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here

	    TargetPos[0]-=1,TargetPos[1]-=1;
	    int ans=0;
	    vector<vector<bool>>vis(N,vector<bool>(N,false));
	    vector<vector<int>>dim={{-2,-1},{-2,+1},{+2,-1},{+2,+1},{-1,-2},{-1,+2},{+1,-2},{+1,+2}};
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0]-1,KnightPos[1]-1});
	    vis[KnightPos[0]-1][KnightPos[1]-1]=true;
	    
	    while(q.size())
	    {
	        int sz=q.size();
	        for(int i=0;i<sz;i++)
	        {
	            auto p=q.front();q.pop();
	            int r=p.first,c=p.second;
	            
	            for(int j=0;j<8;j++)
	            {
	                int x=dim[j][0] + r, y=dim[j][1]+c;
	                
	                if(x<0 or y<0 or x>=N or y>=N or vis[x][y]==true)
	                continue;
	                
	                if(x==TargetPos[0] and y==TargetPos[1])
	                return ans+1;
	                
	                q.push({x,y});
	                vis[x][y]=true;
	            }
	        }
	        ans++;
	    }
	    
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends