class Solution {
public:
    long long countSubarrays(vector<int>& arr, int K) {
        
        int n = arr.size(),counter = 0,maxi = 0;
        
        for(int&i : arr){
            maxi = max(i,maxi);
        }
        
        int left = 0, right = 0;
        long long ans = 0LL;

        while (right < n) {
           
            if(arr[right] == maxi)
            counter++;
            
            while (counter>= K) {
                
                if(arr[left] == maxi)
                    counter--;
                
                left++;
                ans += 1LL * (n - right); 
            }

            right++;
        }


        return ans;
    }
};