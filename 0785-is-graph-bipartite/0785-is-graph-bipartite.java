class Solution {
    
    private int n;
    private int[] arr;
    
    private boolean DFS(int node, boolean color, int[][] adj){
        
        if(arr[node] != -1)
            return arr[node] == (color ? 1 : 0);
        
        arr[node] = color ? 1 : 0; // Convert boolean color to int
        boolean ans = true;
        
        for(int neigh : adj[node]){
            ans &=  DFS(neigh, !color, adj);
            
            if(!ans)
                break;
        }
        
        return ans;
    }
    
    public boolean isBipartite(int[][] adj) {
        
        this.n = adj.length;
        this.arr = new int[n];
        
        for(int i = 0; i < n; i++)
            arr[i] = -1;
        
        boolean ans = true;
        
        for(int i=0;i<n;i++){
            if(arr[i]==-1)
                ans &= DFS(i,false,adj);
            
            if(!ans)
                break;
                
        }
        
        return ans;
    }
}
