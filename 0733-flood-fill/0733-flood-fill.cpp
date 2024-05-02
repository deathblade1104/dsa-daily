class Solution {
public:
    int n, m; 
array<int,5>dir;

Solution(){
	dir = {1,0,-1,0,1};
}

	
void helper(int r, int c,vector<vector<int>>&mat,int&srcColor, int color){
	
	if(r<0 or c<0 or r>=n or c>=m or mat[r][c]!=srcColor)
		return;

	mat[r][c] = color;

	for(int i=1;i<=4;i++){
		int x = dir[i-1] + r, y = dir[i]  + c;
		helper(x,y,mat,srcColor,color);
}

return;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

	n = image.size();
	m = image[0].size();
	

	int srcColor = image[sr][sc];
	if(srcColor == color)
		return image;

	helper(sr,sc,image,srcColor,color);
	return image;
       	
	
    }

};