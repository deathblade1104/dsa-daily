/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    private int n;
    private int findPeak(MountainArray arr){

        int low = 0, high = n-1, ans = n+1;
        
        while(low<=high){

            int mid = low + ((high - low)/2);
            int curr = arr.get(mid);
            int prev = mid-1>=0? arr.get(mid-1) : Integer.MIN_VALUE;
            int next = mid+1<=n-1? arr.get(mid+1) : Integer.MIN_VALUE;

            if(curr>prev && curr>next)
                return mid;

            if(curr<prev)
                high = mid-1;

            else low = mid+1;
        }

        return n+1;
    }

    private int findInSubArray(MountainArray arr, int target, int low, int high,boolean isIncreasing){

        int ans = n+1;

        while(low<=high){

            int mid = low + ((high - low)/2);
            int curr = arr.get(mid);

            if(curr == target)
                return mid;

            if(isIncreasing){
                if(curr<target)
                    low = mid + 1;

                else high = mid -1;
            }

            else {
                if(curr>target){
                    low = mid + 1;   
                }
                else high = mid -1;
            }
           
        }

        return ans;
    }
    public int findInMountainArray(int target, MountainArray arr) {
        n = arr.length();

        int peak = this.findPeak(arr);
        if(peak == n+1)
            return -1;

        int ans = Math.min(findInSubArray(arr,target,0,peak,true),findInSubArray(arr,target,peak+1,n-1,false));

        if(ans == n+1)
            return -1;
        
        return ans;
    }
}   