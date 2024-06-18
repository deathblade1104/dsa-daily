class Solution {
    
    private int getMaxProfit(int currDifficulty, int n, int[][] arr){
        
        int low =0, high = n-1,ans = 0;
        
        while(low<=high){
            int mid = low + ((high - low)/2);
            
            if(arr[mid][0]<=currDifficulty){
                ans = arr[mid][1];
                low = mid +1;
            }
            
            else high = mid - 1;
        }
        
        return ans;
    }
    
    
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        
        int n = profit.length;
        int [][] arr = new int[n][2];
        
        for (int i = 0; i < n; i++) {
            arr[i][0] = difficulty[i];
            arr[i][1] = profit[i];
        }
        
        Arrays.sort(arr, Comparator.comparingInt(a -> a[0]));
        
        for(int i=1;i<n;i++){
            arr[i][1] = Math.max(arr[i][1],arr[i-1][1]);
        }
        
        
        int ans = 0;
        
        for(int i=0;i<worker.length;i++){
            ans+=this.getMaxProfit(worker[i],n,arr);
        }
        
        return ans;    
    }
}