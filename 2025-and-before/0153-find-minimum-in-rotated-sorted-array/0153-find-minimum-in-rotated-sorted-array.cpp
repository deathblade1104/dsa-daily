class Solution {
public:
    int findMin(vector<int>& arr) {
        
        int low = 0,high = arr.size() - 1, ans = INT_MAX;
        
        while(low<=high){
            int mid = low + ((high - low)/2);
            if(arr[mid]<arr[0]){
                ans = arr[mid];
                high = mid - 1;
            }
            
            else low = mid + 1;
        }
        
        return min(ans,arr[0]);
    }
};