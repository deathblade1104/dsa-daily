class Solution {

    private static class DisjointSet {
        int[] par, rank;
        boolean[] isOn;
        TreeSet<Integer>[] st;
        int n;

        DisjointSet(int n) {
            this.n = n;
            par = new int[n + 1];
            rank = new int[n + 1];
            isOn = new boolean[n + 1];
            st = new TreeSet[n + 1];

            for (int i = 1; i <= n; i++) {
                par[i] = i;
                rank[i] = 0;
                isOn[i] = true;
            }
        }

        int findPar(int p) {
            if (par[p] == p) return p;
            return par[p] = findPar(par[p]);
        }

        void merge(int u, int v) {
            int p1 = findPar(u), p2 = findPar(v);
            if (p1 == p2) return;

            if (rank[p1] >= rank[p2]) {
                par[p2] = p1;
                if (rank[p1] == rank[p2]) rank[p1]++;
            } else {
                par[p1] = p2;
            }
        }

        void build() {
            for (int i = 1; i <= n; i++) {
                int p = findPar(i);
                if (st[p] == null)
                    st[p] = new TreeSet<>();
                st[p].add(i);
            }
        }

        int findSmallestInComponent(int u) {
            if (isOn[u])
                return u;

            int p = findPar(u);
            TreeSet<Integer> curr = st[p];
            if (curr == null || curr.isEmpty())
                return -1;

            return curr.first();
        }

        void remove(int u) {
            if (!isOn[u])
                return;

            isOn[u] = false;
            TreeSet<Integer> curr = st[findPar(u)];
            if (curr != null)
                curr.remove(u);
        }
    }

    public int[] processQueries(int c, int[][] edges, int[][] queries) {
        DisjointSet dsu = new DisjointSet(c);
        for (int[] edge : edges)
            dsu.merge(edge[0], edge[1]);

        dsu.build();

        List<Integer> ansList = new ArrayList<>();
        for (int[] q : queries) {
            if (q[0] == 1)
                ansList.add(dsu.findSmallestInComponent(q[1]));
            else
                dsu.remove(q[1]);
        }

        int[] res = new int[ansList.size()];
        for (int i = 0; i < res.length; i++)
            res[i] = ansList.get(i);

        return res;
    }
}
