class Solution {
    private int n;
    
    private boolean isPossible(int mid, int[] arr, int m){
        
        m--;
        int start = 0;
        
        for(int i=1;i<n;i++){
            if(arr[i] - arr[start]>=mid){
                m--;
                start = i;
            }
            
            if(m == 0)
                return true;
        }
        
        return false;
    }
    
    public int maxDistance(int[] arr, int m) {
        
        Arrays.sort(arr);
        n = arr.length;
        int low = arr[n-1],high = arr[n-1] - arr[0],ans = -1;
        
        for(int i=1;i<n;i++){
            low = Math.min(arr[i-1] - arr[i], low);
        }
        
        while(low<=high){
            int mid  = low + ((high - low)/2);
            
            if(isPossible(mid,arr,m)){
                ans = mid;
                low = mid+1;
            }
            
            else high = mid - 1;
        }
        
        return ans;
            
    }
}