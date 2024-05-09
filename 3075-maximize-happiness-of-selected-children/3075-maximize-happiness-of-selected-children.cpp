class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        long long ans = 0;
        sort(arr.rbegin(),arr.rend());
        int i=0,n =arr.size();
        
        while(i<n and k--){
            long long curr = arr[i] - i;    
            
            if(curr<=0)
                break;
            
            ans+=(1LL *curr);
            i++;
        }
        
        return ans;
        
    }
};