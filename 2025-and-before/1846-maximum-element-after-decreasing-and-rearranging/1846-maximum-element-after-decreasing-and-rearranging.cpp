class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0] = 1;
        int ans = 1;
        
        for(int i=1;i<arr.size();i++){
            
            if(abs(arr[i] - arr[i-1])>1){
                arr[i] = 1 + arr[i-1];
            }
            
            ans = max(ans,arr[i]);
        }
        
        return ans;
    }
};