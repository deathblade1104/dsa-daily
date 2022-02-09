// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void solve(int r, int c, int &n, int &m , int color, int newColor, vector<vector<int>>&image)
    {
        
        if(r<0 or r>=n or c<0 or c>=m or image[r][c]!=color)
        return;

        // cout<<r<<" "<<c<<endl;
        
        image[r][c]=newColor;
        
        solve(r+1,c,n,m,color,newColor,image);
        solve(r-1,c,n,m,color,newColor,image);
        solve(r,c+1,n,m,color,newColor,image);
        solve(r,c-1,n,m,color,newColor,image);

        
        return;
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        
        int n=image.size(),m=image[0].size();
        int color=image[sr][sc];
        
        if(color==newColor)
        return image;
        
        
        solve(sr,sc,n,m,color,newColor,image);
        
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