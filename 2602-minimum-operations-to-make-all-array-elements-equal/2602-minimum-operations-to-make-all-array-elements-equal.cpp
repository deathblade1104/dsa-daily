class Solution {
public:
    long long int pref[(int)(1e5 + 1)];
    int n;
    vector<long long> ans;
    
    int getLb(vector<int>& nums, int curr) {
        int low = 0, high = n - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < curr) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    
    int getHb(vector<int>& nums, int curr) {
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > curr) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    long long int getSum(int l, int r) {
        long long int prefSum = pref[r];
        if (l >= 1) {
            prefSum -= pref[l - 1];
        }
        return prefSum;
    }
    
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        memset(pref, 0, sizeof pref);
        n = nums.size();
        for (int i = 0; i < n; i++) {
            pref[i] += (1LL * nums[i]);
            if (i > 0) {
                pref[i] += pref[i - 1];
            }
        }
        int q = queries.size();
        ans.resize(q);
        for (int i = 0; i < q; i++) {
            int l = getLb(nums, queries[i]);
            int r = getHb(nums, queries[i]);
            ans[i] = 0LL;
            if (l >= 0) {
                ans[i] += (1LL * queries[i] * (l + 1)) - getSum(0, l);
            }
            if (r < n) {
                ans[i] += getSum(r, n - 1) - (1LL * queries[i] * (n - r));
            }
        }
        return ans;
    }
};
