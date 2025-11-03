class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
     int ans = INT_MAX;
    set<int> s;
    for(int i = x; i < nums.size(); ++i){
        s.insert(nums[i-x]);
        auto it = s.upper_bound(nums[i]);
        if(it != s.end()) ans = min(ans, abs(nums[i] - *it));
        if(it != s.begin()) ans = min(ans, abs(nums[i] - *prev(it)));
    }
    return ans;
        
    }
};