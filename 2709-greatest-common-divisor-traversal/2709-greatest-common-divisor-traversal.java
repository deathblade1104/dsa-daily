class DSU {
    private int[] par, rank;

    public DSU(int n) {
        par = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            this.par[i] = i;
            this.rank[i] = 0;
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
    private static boolean[] prime;
    private static int[] spf;
    private final static int sz = 100001;
    private boolean flag = false;
    
    public Solution(){
        
        if(!flag){
            sieve();
        }
        
        flag = true;
        
    }
    
    private void sieve(){
        prime = new boolean[sz];
        spf = new int[sz];

        for (int i = 0; i < sz; i++) {
            prime[i] = true;
            spf[i] = i;
        }

        prime[0] = prime[1] = false;

        for (int i = 2; i < sz; i++) {
            for (int j = i * i; j < sz; j += i) {
                if(j<0)
                    break;
                
                if (prime[j] == true) {
                    spf[j] = i;
                }
                prime[j] = false;
            }
        }
    }

    public HashSet<Integer> getPrimeFactors(int x) {
        HashSet<Integer> st = new HashSet<>();

        while (x > 1) {
            st.add(spf[x]);
            x /= spf[x];
        }

        return st;
    }

    public boolean canTraverseAllPairs(int[] nums) {
        int n = nums.length;
        
        if(n == 1 )
            return true;
        HashMap<Integer, ArrayList<Integer>> mp = new HashMap<>();

        for (int i : nums) {

            if (i == 1)
                return false;

            HashSet<Integer> st = getPrimeFactors(i);

            for (int p : st) {
                ArrayList<Integer> curr = mp.getOrDefault(p, new ArrayList<>());
                curr.add(i);
                mp.put(p, curr);
            }
        }

        DSU object = new DSU(sz);

        for (Map.Entry<Integer, ArrayList<Integer>> entry : mp.entrySet()) {

            ArrayList<Integer> curr = entry.getValue();

            for (int i = 1; i < curr.size(); i++) {
                object.join(curr.get(i - 1), curr.get(i));
            }
        }

        for (int i = 1; i < n; i++) {

            if (!object.isConnected(nums[i - 1], nums[i]))
                return false;
        }

        return true;
    }
}
