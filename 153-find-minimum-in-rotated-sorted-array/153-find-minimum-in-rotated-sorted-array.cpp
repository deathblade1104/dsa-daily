class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0 , high = arr.size()-1;
        
        if(arr[low]<arr[high] or high==0)
            return arr[low];
        
        while(low<=high)
        {
            int mid = low + ((high - low)/2);
            
            if(mid!=0 and arr[mid]<arr[mid-1])
                return arr[mid];
            
            else if(mid!=arr.size()-1 and arr[mid]>arr[mid+1])
                return arr[mid+1];
            
            if(arr[low]<arr[mid])
                low= mid +1;
            
            else 
                high = mid - 1;            
        }
        
        return -1;
    }
};