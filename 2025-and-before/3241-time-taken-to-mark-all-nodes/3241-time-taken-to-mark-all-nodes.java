class Solution {
    
    private ArrayList<Integer>[] adj;
    private int[] first, second, ans;
    
    private void DFS1(int curr, int par){
        for (int neigh : adj[curr]) {
            if (neigh == par) continue;
            DFS1(neigh, curr);
            
            int w = (neigh % 2 == 0) ? 2 : 1;
            int currTime = first[neigh] + w;
            
            if (currTime > first[curr]) {
                second[curr] = first[curr];
                first[curr] = currTime;
            } else if (currTime > second[curr]) {
                second[curr] = currTime;
            }
        }
    }
    
    private void DFS2(int curr, int par, int abovePar) {
        ans[curr] = Math.max(abovePar, first[curr]);
        
        for (int neigh : adj[curr]) {
            if (neigh == par) continue;
            
            int w_curr2Neigh = (neigh % 2 == 0) ? 2 : 1;
            int w_neigh2Curr = (curr % 2 == 0) ? 2 : 1;
            
            if (first[neigh] + w_curr2Neigh == first[curr]) {
                DFS2(neigh, curr, Math.max(abovePar, second[curr]) + w_neigh2Curr);
            } else {
                DFS2(neigh, curr, ans[curr] + w_neigh2Curr);
            }
        }
    }
    
    public int[] timeTaken(int[][] edges) {
        int n = edges.length + 1;
        
        adj = new ArrayList[n];
        first = new int[n];
        second = new int[n];
        ans = new int[n];
        
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].add(v);
            adj[v].add(u);
        }
        
        DFS1(0, -1);
        DFS2(0, -1, 0);
        
        return ans;
    }
}