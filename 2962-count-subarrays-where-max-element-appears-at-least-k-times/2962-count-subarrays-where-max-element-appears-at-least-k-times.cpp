class Solution {
public:
    long long countSubarrays(vector<int>& arr, int K) {
        
        int n = arr.size();
        unordered_map<int, int> frequency;
        int maxi = 0;
        for(int&i : arr){
            maxi = max(i,maxi);
        }
        
        int left = 0, right = 0;
        long long count = 0LL;

        while (right < n) {
           
            frequency[arr[right]]++;
            
            while (frequency[maxi] >= K) {
                frequency[arr[left]]--;
                left++;
                count += 1LL * (n - right); 
            }

            right++;
        }


        return count;
    }
};