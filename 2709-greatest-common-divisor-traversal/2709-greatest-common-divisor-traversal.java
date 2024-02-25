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
    
    private HashMap<Integer, ArrayList<Integer>>mp;
    private static final int sz = 100001;
    
    public void getPrimeFactors(int x,int idx) {
        
        
        ArrayList<Integer>curr;
        
        if(x%2 == 0){
            
            curr = mp.getOrDefault(2,new ArrayList<>());
            curr.add(idx);
            mp.put(2,curr);
            
            while(x%2 == 0)
                x/=2;
        }
        
        if(x%3 == 0){
    
            curr = mp.getOrDefault(3,new ArrayList<>());
            curr.add(idx);
            mp.put(3,curr);
            
            while(x%3 == 0)
                x/=3;
            
        }
        
        
        for(int i=5;i*i<=x;i+=6){
            if(x%i== 0){
                
                curr = mp.getOrDefault(i,new ArrayList<>());
                curr.add(idx);
                mp.put(i,curr);

                while(x%i == 0)
                    x/=i;
            }
            
            int j=i+2;
            
            if(x%j== 0){    
                curr = mp.getOrDefault(j,new ArrayList<>());
                curr.add(idx);
                mp.put(j,curr);

                while(x%j == 0)
                    x/=j;
            }   
        }
        
        if(x>1){
            
            curr = mp.getOrDefault(x,new ArrayList<>());
            curr.add(idx);
            mp.put(x,curr);
            
        }
        
    }
    
    public boolean canTraverseAllPairs(int[] nums) {
        int n = nums.length;
        
        if(n == 1 )
            return true;
        
        mp = new HashMap<>();

        for (int idx=0;idx<n;idx++) {
            
            int i = nums[idx];
            
            if (i == 1)
                return false;
            
            getPrimeFactors(i,idx);
        }

        DSU object = new DSU(n);

        for (Map.Entry<Integer,ArrayList<Integer>> entry : mp.entrySet()) {
            ArrayList<Integer>arr = entry.getValue();
            
            for (int i = 1; i < arr.size(); i++) {
                object.join(arr.get(i - 1), arr.get(i));
            }
        }

        for (int i = 1; i < n; i++) {

            if (!object.isConnected(i-1,i))
                return false;
        }

        return true;
    }
}
