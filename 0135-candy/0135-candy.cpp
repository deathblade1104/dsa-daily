class Solution {
public:
    int candy(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>ans(n,1);
        
        for(int i=1;i<n;i++){
            
            if(arr[i]>arr[i-1])
                ans[i] = 1 + ans[i-1];
        }
        
        for(int i=n-2;i>=0;i--){
            
            if(arr[i]>arr[i+1]){
                ans[i] = max(ans[i],1+ans[i+1]);
            }
        }
        
        
        return accumulate(ans.begin(),ans.end(),0);
        
        
    }
};