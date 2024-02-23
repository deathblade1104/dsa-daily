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
        
        
        while(!q.isEmpty()){
            
            int curr = q.poll();
            arr.add(curr);
            
            for(int neigh : adj.get(curr)){
                
                inEdge[neigh]--;
                
                if(inEdge[neigh] == 0)
                    q.offer(neigh);
            }
        }
        
        
        if(arr.size() != n)
            return (new int[0]);
        
        int[] ans = new int[n];
        
        for(int i=0;i<n;i++)
            ans[i] = arr.get(i);
        
        return ans;

    }
}