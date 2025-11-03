class Solution {
public:
    int arr[100001];
    int arr2[100001];
    int bestClosingTime(string customers) {
        
        
        int n = customers.size();
        memset(arr,0,sizeof arr);
        memset(arr2,0,sizeof arr);
        
        arr[0] = (customers[0] == 'Y')? 1 : 0;
        arr2[0] = (customers[0] == 'N')? 1 : 0;
        
        
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
            arr[i]+=(customers[i] == 'Y')? 1 : 0;
            
            arr2[i]+=arr2[i-1];
            arr2[i]+=(customers[i] == 'N')? 1 : 0;
        }
        
        int total  = arr[n-1],res, ans;
        
        res = n - arr[n-1];
        ans = n;
        
        for(int i=n-1;i>=0;i--){
            
            int curr = (customers[i] == 'Y')? 1 : -1;
            curr+=arr[n-1] - arr[i];
            curr+=arr2[i];
            
            if(curr<=res){
                res = curr;
                ans = i;
            }
        }
        
        return ans;
    }
};