// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        
        if(image[sr][sc]==newColor)
        return image;
        
        int n=image.size(),m=image[0].size(),i=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        while(q.size()!=0)
        {
            pair<int,int>p=q.front();q.pop();
            
            int r=p.first,c=p.second;
            
            if(r<0 or r>=n or c<0 or c>=m or image[r][c]!=i)
            continue;
            
            image[r][c]=newColor;
            
            q.push({r+1,c});
            q.push({r-1,c});
            q.push({r,c+1});
            q.push({r,c-1});
        }
        
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends