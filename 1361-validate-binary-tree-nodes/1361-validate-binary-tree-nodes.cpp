class Solution {
public:
    int inEdge[10001];
    vector<unordered_set<int>>adj;
    bool vis[10001];
    
    bool validDFS(int root){
        
        if(vis[root])
            return false;
        
        //cout<<"currNode : "<<root<<endl;
        
        vis[root]  = true;
        bool ans = true;
        
        for(int i : adj[root]){
            
            ans = validDFS(i);
            if(!ans)
                return false;
        }
        
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        memset(inEdge,0,sizeof inEdge);
        adj.resize(n);
        
        for(int i=0;i<n;i++){
            
            if(leftChild[i]!=-1){
                if(adj[leftChild[i]].count(i))
                    return false;
                
                inEdge[leftChild[i]]++;
                adj[i].insert(leftChild[i]);
            }
            
            if(rightChild[i]!=-1){
                
                if(adj[rightChild[i]].count(i))
                    return false;
                
                inEdge[rightChild[i]]++;
                adj[i].insert(rightChild[i]);
            }
            
        }    
        
        int zIn= 0,root= -1;
        for(int i=0;i<n;i++){
            
            if(inEdge[i] == 0){
                zIn++;
                
                if(zIn>1)
                    return false;
                
                root = i;
            }
            
            
            if(inEdge[i]>1)
                return false;
        }
        
        if(zIn == 0)
            return false;
        
        if(adj[root].size() == 0 and n>1)
            return false;
        
        memset(vis,0,sizeof vis);
        bool temp = validDFS(root);
        
        if(!temp)
            return false;
        
        for(int i=0;i<n;i++){
            if(!vis[i])
                return false;
        }
        
        return true;
        
        
    }
};