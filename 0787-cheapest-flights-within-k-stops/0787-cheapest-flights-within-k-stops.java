import java.util.*;


class Solution {
    private List<int[]>[] adj;
    private  int[] dist;
    
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        adj = new ArrayList[n];
        
        // Initialize adjacency list
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        
        for (int[] flight : flights) {
            adj[flight[0]].add(new int[] {flight[1], flight[2]});
        }
        
        // Initialize distance array
        dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        
        // Perform BFS
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{src, 0});
        int steps = 0;
        
        while (steps <= k && !q.isEmpty()) {
            int sz = q.size();
            while (sz-- > 0) {
                int[] arr = q.poll();
                int node = arr[0], cost = arr[1];
                
                for (int[] v : adj[node]) {
                    int neigh = v[0], neighDist = v[1] + cost;
                    if (dist[neigh] > neighDist) {
                        dist[neigh] = neighDist;
                        q.offer(new int[]{neigh, neighDist});
                    }
                }
            }
            steps++;
        }
        
        return dist[dst] == Integer.MAX_VALUE ? -1 : dist[dst];
    }
}
