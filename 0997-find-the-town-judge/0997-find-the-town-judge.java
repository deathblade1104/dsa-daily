class Solution {
    
    private int[] inEdge = new int[1002];
    private int[] outEdge = new int[1002];
    
    
//     Solution(){
//         inEdge  
//         outEdge = new int[1002];
//     }
    
    public int findJudge(int n, int[][] trust) {
     
        for(int i=1;i<=n;i++){
            inEdge[i] = outEdge[i] = 0;
        }
        
        
        
        for(int i=0;i<trust.length;i++){
            int a = trust[i][0], b = trust[i][1];
            
            inEdge[b]++;
            outEdge[a]++;
        }
        
        
        for(int i=1;i<=n;i++){
            if(outEdge[i] == 0 && inEdge[i] == n-1)
                return i;
        }
        
        return -1;
        
        
        
    }
}