class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        
        if (n == 1) {
            return Collections.singletonList(0);
        }
        
        int[] inEdges = new int[n];
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(n);
        
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0], v = edges[i][1];
            inEdges[u]++;
            inEdges[v]++;
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        Queue<Integer> q = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            if (inEdges[i] == 1) {
                q.add(i);
            }
        }
        
        List<Integer> ans = new ArrayList<>();
        
        while (!q.isEmpty()) {
            int sz = q.size();
            List<Integer> res = new ArrayList<>();
            while (sz-- > 0) {
                int curr = q.poll();
                res.add(curr);
                
                for (int neigh : adj.get(curr)) {
                    inEdges[neigh]--;
                    
                    if (inEdges[neigh] == 1) {
                        q.add(neigh);
                    }
                }
            }
            
            ans = res;
        }
        
        return ans;
    }
}
