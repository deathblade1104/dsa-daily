class Solution {
    public int[] findOrder(int n, int[][] edges) {
        int[] inEdge  = new int[n];
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(n);
        
        for(int i=0;i<n;i++){
            inEdge[i] = 0;
            adj.add(new ArrayList<>());
        }
        
    
        for(int i=0;i<edges.length;i++){
            int u = edges[i][0], v = edges[i][1];
            inEdge[u]++;
            adj.get(v).add(u);
        }
        
        Queue<Integer>q = new LinkedList<>();
        ArrayList<Integer> arr = new ArrayList<>();
        
        for(int i=0;i<n;i++){
            if(inEdge[i] == 0)
                q.offer(i);

        }
        
        int[] ans = new int[n];
        int iter = 0;
        
        while(!q.isEmpty()){
            
            int curr = q.poll();
            ans[iter++] = curr;
            
            for(int neigh : adj.get(curr)){
                
                inEdge[neigh]--;
                
                if(inEdge[neigh] == 0)
                    q.offer(neigh);
            }
        }
        
        
        if(iter != n)
            return (new int[0]);
        
        return ans;

    }
}