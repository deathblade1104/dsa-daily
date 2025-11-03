class DSU {
    public int[] par, rank;

    public DSU(int n) {
        par = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    public int findPar(int p) {
        if (par[p] == p)
            return p;

        return par[p] = findPar(par[p]);
    }

    public void join(int u, int v) {
        int p1 = findPar(u), p2 = findPar(v);

        if (p1 == p2)
            return;

        if (rank[p1] >= rank[p2]) {
            rank[p1]++;
            par[p2] = p1;
        } else {
            rank[p2]++;
            par[p1] = p2;
        }
    }

    public boolean isConnected(int u, int v) {
        return findPar(u) == findPar(v);
    }
}

class Solution {
    public int minSwapsCouples(int[] row) {

        int n = row.length;
        DSU obj = new DSU(n / 2);

        for (int i = 0; i < n; i += 2) {
            int a = row[i] / 2, b = row[i + 1] / 2;
            if (!obj.isConnected(a, b))
                obj.join(a, b);
        }

        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            if (obj.findPar(i) != i)
                ans++;
        }

        return ans;
    }
}
