// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    TargetPos[0]-=1,TargetPos[1]-=1;
	    int ans=0;
	    vector<vector<bool>>vis(N,vector<bool>(N,false));
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0]-1,KnightPos[1]-1});
	    
	    while(q.size())
	    {
	        int sz=q.size();
	        for(int i=0;i<sz;i++)
	        {
	            auto p=q.front();q.pop();
	            int r=p.first,c=p.second;
	            
	            if(r<0 or c<0 or r>=N or c>=N or vis[r][c]==true)
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