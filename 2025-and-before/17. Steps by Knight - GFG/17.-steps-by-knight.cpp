// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    KnightPos[0]-=1;
	    KnightPos[1]-=1;
	    TargetPos[0]-=1;
	    TargetPos[1]-=1;
	    
	    int ans=0;
	    vector<vector<bool>>vis(n,vector<bool>(n,false));
	    
	    
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});
	    
	    while(q.size())
	    {
	        int sz=q.size();
	        for(int i=0;i<sz;i++)
	        {
	            auto p=q.front();
	            q.pop();
	            
	            int r=p.first,c=p.second;
	            
	            if(r<0 or r>=n or c<0 or c>=n or vis[r][c]==true)
	            continue;
	            
	            if(r==TargetPos[0] and c==TargetPos[1])
	            return ans;
	            
	            vis[r][c]=true;
	            
	            q.push({r-2,c-1});
	            q.push({r-2,c+1});
	            q.push({r+2,c-1});
	            q.push({r+2,c+1});
	            
	            q.push({r-1,c-2});
	            q.push({r-1,c+2});
	            q.push({r+1,c-2});
	            q.push({r+1,c+2});
	        }
	        ans++;
	    }
	    
	    return -1;

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