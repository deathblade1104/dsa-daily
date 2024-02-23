class Solution {
    ArrayList<ArrayList<int[]>> adj;
    ArrayList<Integer> dist;
    Queue<int[]> q;

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        adj = new ArrayList<>(n);
        dist = new ArrayList<>(n);
        
        // Initialize dist with Integer.MAX_VALUE
        for (int i = 0; i < n; i++) {
            dist.add(Integer.MAX_VALUE);
            adj.add(new ArrayList<>());
        }
        
        
        for (int[] flight : flights) {
            adj.get(flight[0]).add(new int[] { flight[1], flight[2] });
        }
        
        q = new LinkedList<>();
        q.offer(new int[]{src, 0});
        int steps =0;
        while (steps<=k && !q.isEmpty()) {
            int sz = q.size();
            while (sz-- > 0) {
                int[] curr = q.poll();
                for (int[] neigh : adj.get(curr[0])) {
                    int neighNode = neigh[0], neighDist = neigh[1] + curr[1];
                    if (dist.get(neighNode) > neighDist) {
                        dist.set(neighNode, neighDist);
                        q.offer(new int[]{neighNode, neighDist});
                    }
                }
            }
            steps++;
        }
        
        return dist.get(dst) == Integer.MAX_VALUE ? -1 : dist.get(dst);   
    }
}
