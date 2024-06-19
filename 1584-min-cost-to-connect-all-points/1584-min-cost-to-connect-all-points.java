class Solution {
    
    private ArrayList<int[]> edges;
    private int n;
    private int[] par, rank;

    
    private int findPar(int p) {
        if (par[p] == p)
            return par[p];
        return par[p] = findPar(par[p]);
    }

    
    private int DSUnion(int[] edge) {
        int dist = edge[0], u = edge[1], v = edge[2];
        int p1 = findPar(u), p2 = findPar(v);
        
        if (p1 == p2)
            return 0;

        if (rank[p1] >=rank[p2]) {
            par[p2] = p1;
            rank[p1]++;
        } else {
            par[p1] = p2;
            rank[p2]++;
        }

        return dist;
    }

    public int minCostConnectPoints(int[][] points) {
        this.n = points.length;
        this.edges = new ArrayList<>();

        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = Math.abs(points[i][0] - points[j][0]);
                int y = Math.abs(points[i][1] - points[j][1]);
                int dist = x + y;
                edges.add(new int[]{dist, i, j});
            }
        }

    
        this.par = new int[n];
        this.rank = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }


        Collections.sort(edges, (a, b) -> Integer.compare(a[0], b[0]));

        int ans = 0;


        for (int i = 0; i < edges.size(); i++) {
            ans += DSUnion(edges.get(i));
        }

        return ans;
    }
}