class Solution {
public:
    int search(vector<int>& arr, int target) {
        
        int low =0, high = arr.size()-1;
        
        while(low<=high)
        {
            int mid= low  + ((high-low)/2);
            
            if(arr[mid]==target)
                return mid;
            
            else if(arr[low]<arr[mid])
            {
                if(target>=arr[low] and target<arr[mid])
                    high = mid-1;
                
                else low = mid +1;
            }
            
            else if (low==mid)
                low=mid+1;
            
            else if (high==mid)
                high=mid-1;
            
            else
            {
                if(target>arr[mid] and target<=arr[high])
                    low = mid +1;
                
                else high = mid -1;
            }
            
        }
        
        return -1;
        
    }
};