class Solution {
private:
    void DFS(int r, int c, int &n,int &m, vector<vector<int>>&image,int &ic, int &nc)
    {
        if(r<0 or c<0 or r>=n or c>=m or image[r][c]==nc or image[r][c]!=ic)
            return;
        
        image[r][c]=nc;
        
        DFS(r+1,c,n,m,image,ic,nc);
        DFS(r-1,c,n,m,image,ic,nc);
        DFS(r,c+1,n,m,image,ic,nc);
        DFS(r,c-1,n,m,image,ic,nc);
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc]==newColor)
            return image;
        
        int n=image.size(),m=image[0].size(),ic=image[sr][sc];
        DFS(sr,sc,n,m,image,ic,newColor);
        
        return image;
        
    }
};