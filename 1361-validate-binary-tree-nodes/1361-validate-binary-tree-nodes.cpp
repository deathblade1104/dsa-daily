class Solution {
public:
    int inEdge[10001];
    bool vis[10001];
    
    bool validDFS(int root,vector<int>& leftChild, vector<int>& rightChild){
        if(vis[root])
            return false;
        
        vis[root]  = true;
        bool ans = true;
        
        if(leftChild[root]!=-1)
            ans = ans & validDFS(leftChild[root],leftChild,rightChild);
        
        if(rightChild[root]!=-1)
            ans = ans & validDFS(rightChild[root],leftChild,rightChild);
        
        return ans;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        memset(inEdge,0,sizeof inEdge);
        
        for(int i=0;i<n;i++){
    
            if(leftChild[i]!=-1){
                inEdge[leftChild[i]]++;
                
                if(inEdge[leftChild[i]]>1)
                    return false;
            }
            
            if(rightChild[i]!=-1){
                inEdge[rightChild[i]]++;
                
                if(inEdge[rightChild[i]]>1)
                    return false;
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
        }
        
        if(zIn == 0)
            return false;
        
        memset(vis,0,sizeof vis);
        
        if(!validDFS(root,leftChild,rightChild))
            return false;
        
        for(int i=0;i<n;i++){
            if(!vis[i])
                return false;
        }
        
        return true;
        
        
    }
};