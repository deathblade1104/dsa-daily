class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        
        int low = 0, high = n-1;        
        
        while(low<=high)
        {
            int mid = low + ((high - low)/2);
            int prev = mid == 0? INT_MIN : arr[mid-1];
            int next = mid == n-1 ? INT_MIN : arr[mid+1];
            
            if(prev<arr[mid] and arr[mid]<next)
                low  = mid + 1;
            
            else if(prev>arr[mid] and arr[mid]>next)
                 high = mid - 1;
            
            else return mid;
        }
        
        return -1;
    }
};