class Solution {
    public int minimumTime(int n, int[][] edges, int[] time) {

        ArrayList<ArrayList<Integer>>adj = new ArrayList<>(n+1);
        
        for(int i=0;i<=n;i++)
            adj.add(new ArrayList<>());

        int[] inEdge = new int[n+1];

        for(int[] edge : edges){
            adj.get(edge[0]).add(edge[1]);
            inEdge[edge[1]]++;
        }

        Queue<Integer>queue = new ArrayDeque<>();
        int[] vis = new int[n+1];
        int ans = 0;

        for(int i=1;i<=n;i++){

            if(inEdge[i]>0)
                continue;
            
            queue.offer(i);
            vis[i] = time[i-1];
            ans = Math.max(ans,vis[i]);
        }


        while(!queue.isEmpty()){
            int curr = queue.poll();

            for(int neigh : adj.get(curr)){

                inEdge[neigh]--;
                vis[neigh] = Math.max(vis[neigh],time[neigh-1] + vis[curr]);
                ans = Math.max(ans,vis[neigh]);

                if(inEdge[neigh] == 0){
                    queue.offer(neigh);
                }
            }
        }

        return ans;
    }
}