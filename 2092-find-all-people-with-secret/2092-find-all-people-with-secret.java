import java.util.*;

class Solution {
    
    private static class DSU {
    
        int[] par, rank;

        DSU(int n){
            par = new int[n];
            rank = new int[n];
            for(int i=0;i<n;i++){
                par[i] = i;
                rank[i] = 0;
            }
        }
        
        int findPar(int i){
            if(par[i] == i)
                return i;
            
            return par[i] = findPar(par[i]);
        }
        
        
        void reset(int i){
            par[i] = i;
            rank[i] = 0;
        }
        
        void join(int u, int v){
            int uPar = findPar(u), vPar = findPar(v);
            
            if(rank[uPar]>=rank[vPar]){
                rank[uPar]++;
                par[vPar] = uPar;
            } else {
                rank[vPar]++;
                par[uPar] = vPar;
            }
        }
        
        boolean isConnected(int u, int v){
            return findPar(u) == findPar(v);
        }
    }
    
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[2]));
        DSU object = new DSU(n);
        object.join(0, firstPerson);
        
        
        
        int i = 0;
        int m = meetings.length; // Rename 'n' to 'm' here
        
        while(i < m){ // Use 'm' instead of 'n' here
            
           HashSet<Integer> st = new HashSet<>();
            int currTime =  meetings[i][2];
            
            for(; i < m && meetings[i][2] == currTime; i++){
                
                int u = meetings[i][0], v = meetings[i][1];
                
                st.add(u);
                st.add(v);
                
                object.join(u, v);
            }
            
            for(int curr : st){
                if(!object.isConnected(0, curr)){
                    object.reset(curr);
                }
            }
        }
        
        List<Integer> ans = new ArrayList<>();
        
        for(int j = 0; j < n; j++){ // Iterate up to 'n' here, not 'm'
            if(object.isConnected(0, j))
                ans.add(j);
        }
        
        return ans;
        
    }
}
