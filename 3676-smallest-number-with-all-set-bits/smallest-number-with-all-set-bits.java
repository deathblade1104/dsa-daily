class Solution {
    private static final int[] arr = new int[]{2,4,8,16,32,64,128,256,512,1024};

    public int smallestNumber(int n) {

        int low =0, high = arr.length - 1,ans = -1;

        while(low<=high){

            int mid = low + ((high - low)/2);
            if(arr[mid]>n){
                ans = mid;
                high = mid - 1;
            }

            else low = mid+1;
        }    

        return arr[ans] - 1;

    }
}