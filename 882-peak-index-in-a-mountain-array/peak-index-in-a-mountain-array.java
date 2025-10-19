class Solution {
    public int peakIndexInMountainArray(int[] arr) {


        int low = 0, n = arr.length, high = n-1;
        
        while(low<=high){
            int mid = low + ((high - low)/2);
            int prev = mid == 0? Integer.MIN_VALUE : arr[mid-1];
            int next = mid == n-1 ? Integer.MIN_VALUE : arr[mid+1];
            
            if(prev<arr[mid] && arr[mid]<next)
                low  = mid + 1;
            
            else if(prev>arr[mid] && arr[mid]>next)
                 high = mid - 1;
            
            else return mid;
        }
        
        return -1;
        
    }
}