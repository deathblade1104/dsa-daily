class Solution {
public:
    int search(vector<int>& arr, int target) {
        int sz = arr.size(), low = 0, high = sz -1;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(arr[mid] == target)
                return mid;
            
            if(arr[low]<=arr[mid]){
                if(arr[low]<=target and target<=arr[mid])
                    high = mid - 1;
                
                else
                    low = mid + 1;
            }
            
            else if(arr[mid]<=arr[high]) {
                if(arr[mid]<=target and target<=arr[high])
                    low = mid + 1;
                
                else
                    high = mid -1;
            }
        }
        
        return -1;
        
    }
};