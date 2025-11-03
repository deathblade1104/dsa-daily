class Solution {
public:
    
    unordered_map<int,int> getAdj(vector<vector<int>>&board){
        
        int idx = 1;
        int n = board.size();
        bool odd = true;
        unordered_map<int,int>mp;
        
        
        for(int i=n-1;i>=0;i--){
        
            if(!odd){
                for(int j=n-1;j>=0;j--){
                    
                    if(board[i][j]!=-1){
                        
                        mp[idx] = board[i][j];
                    }
                    
                    idx++;

                }
            }
            else{
                for(int j=0;j<n;j++){
                    if(board[i][j]!=-1){
                        
                        mp[idx] = board[i][j];
                    }
                    idx++;
                }
            }
            
            odd = !odd;
        }
        
        return mp;
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        bool vis[(n*n)+1];
        memset(vis,0,sizeof vis);
        
        unordered_map<int,int>mp = getAdj(board);
        
        // for(auto&it : mp){
        //     cout<<it.first<<" ---> "<<it.second<<endl;
        // }
        
        vis[0]=vis[1]= true;
        queue<int>q;
        q.push(1);
        int steps = 0;
        
        while(q.size()){
            
            int sz = q.size();
            while(sz --){
                
                int curr = q.front();
                q.pop();
                
                //cout<<curr<<" : "<<endl;
                
                if(curr == (n *n))
                    return steps;
                
                for(int i=1;i<=6;i++){
                    
                    int newCurr = i + curr;
                    
                    if(newCurr>(n*n))
                        continue;
                    
                    if(mp.count(newCurr) and !vis[mp[newCurr]]){
                        
                        //cout<<mp[newCurr]<<" , ";
                        vis[mp[newCurr]]= true;
                        q.push(mp[newCurr]);
                    }
                    
                    else if(mp.count(newCurr)==0 and !vis[newCurr]){
                        
                        //cout<<newCurr<<" , ";
                        vis[newCurr] = true;
                        q.push(newCurr);
                    }
                }
                //cout<<endl;
            }
            steps++;
        }
        
        return -1;
        
        
    }
};