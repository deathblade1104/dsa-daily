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
            // Expand the window and update frequency
            frequency[arr[right]]++;

            // Shrink the window until the count of occurrences becomes less than K
            while (frequency[maxi] >= K) {
                frequency[arr[left]]--;
                left++;
                count += 1LL * (n - right);  // Subarrays ending at the current position
            }

            // Move to the next element in the array
            right++;
        }


        return count;
    }
};