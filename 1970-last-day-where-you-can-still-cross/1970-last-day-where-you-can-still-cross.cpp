class Solution {
public:
    const int dir[5] = {1,0,-1,0,1};
    int n, m;
    
    
    bool BFS(int mid,vector<vector<int>>&mat){
        
        queue<array<int,2>>q;
        for(int i=0;i<m;i++){
            if(mat[0][i] == -1 ){
                q.push({0,i});
                mat[0][i] = 1;
            }
        }
        
        int steps = 0;
        
        while(q.size() and steps<=mid){
            
            while(q.size()){
                
                int curr_r = q.front()[0],curr_c = q.front()[1];
                q.pop();
                
                if(curr_r == n-1)
                    return true;
                
                for(int k=1;k<=4;k++){    
                    int x= curr_r + dir[k-1],y = curr_c + dir[k];
                    
                    if(x>=0 and y>=0 and x<n and y<m and mat[x][y] == -1){
                        q.push({x,y});
                         mat[x][y] = 1;
                    }
                }
            }
            steps++;
        }
        
        return false;
    }
    
    bool isPossible(int mid,vector<vector<int>>& cells){
        
        vector<vector<int>>mat(n,vector<int>(m,-1));
        
        for(int i =0;i<mid;i++){
            mat[cells[i][0]-1][cells[i][1]-1] = 0;
        }
        
        return BFS(mid,mat);
        //return false;
        
    }
        
        
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row;
        m = col;
        
        int low = 1, high = n*m,ans =0;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            if(isPossible(mid,cells)){
                ans = mid;
                low = mid + 1;
            }
            
            else high = mid -1 ;
        }
        
        return ans;
    }
};