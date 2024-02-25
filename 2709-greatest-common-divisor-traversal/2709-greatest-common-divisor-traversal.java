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
    
    private HashMap<Integer, HashSet<Integer>>mp;
    private static final int sz = 100001;
    
    public void getPrimeFactors(int n) {
        
        int x = n;
        HashSet<Integer>curr;
        
        if(x%2 == 0){
            
            curr = mp.getOrDefault(2,new HashSet<>());
            curr.add(n);
            mp.put(2,curr);
            
            while(x%2 == 0)
                x/=2;
        }
        
        if(x%3 == 0){
    
            curr = mp.getOrDefault(3,new HashSet<>());
            curr.add(n);
            mp.put(3,curr);
            
            while(x%3 == 0)
                x/=3;
            
        }
        
        
        for(int i=5;i*i<=x;i+=6){
            if(x%i== 0){
                
                curr = mp.getOrDefault(i,new HashSet<>());
                curr.add(n);
                mp.put(i,curr);

                while(x%i == 0)
                    x/=i;
            }
            
            int j=i+2;
            
            if(x%j== 0){    
                curr = mp.getOrDefault(j,new HashSet<>());
                curr.add(n);
                mp.put(j,curr);

                while(x%j == 0)
                    x/=j;
            }   
        }
        
        if(x>1){
            
            curr = mp.getOrDefault(x,new HashSet<>());
            curr.add(n);
            mp.put(x,curr);
            
        }
        
    }
    
    public boolean canTraverseAllPairs(int[] nums) {
        int n = nums.length;
        
        if(n == 1 )
            return true;
        
        mp = new HashMap<>();

        for (int i : nums) {

            if (i == 1)
                return false;
            
            getPrimeFactors(i);
        }

        DSU object = new DSU(sz);

        for (Map.Entry<Integer,HashSet<Integer>> entry : mp.entrySet()) {

            HashSet<Integer>st = entry.getValue();
            Integer[] arr = st.toArray(new Integer[0]);
            
            for (int i = 1; i < arr.length; i++) {
                object.join(arr[i - 1], arr[i]);
            }
        }

        for (int i = 1; i < n; i++) {

            if (!object.isConnected(nums[i - 1], nums[i]))
                return false;
        }

        return true;
    }
}
