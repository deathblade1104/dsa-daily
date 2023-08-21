class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int>ans = {-1,-1};
        
        int low = 0, high = arr.size() - 1;
        
        if(high==-1)
            return ans;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(arr[mid]>target)
                high = mid - 1;
            
            else if(arr[mid]<target)
                low  = mid + 1;
            
            else{
                ans[0] = mid;
                
                if(mid==0 or arr[mid-1]!=target)
                    break;
                
                else high = mid -1;
            }
        }
        
        if(ans[0]==-1)
            return ans;
        
        low = 0, high = arr.size() - 1;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(arr[mid]>target)
                high = mid - 1;
            
            else if(arr[mid]<target)
                low  = mid + 1;
            
            else{
                ans[1] = mid;
                
                if(mid==arr.size()-1 or arr[mid+1]!=target)
                    break;
                
                else low = mid + 1;
            }
        }
        
        return ans;
        
    }
};