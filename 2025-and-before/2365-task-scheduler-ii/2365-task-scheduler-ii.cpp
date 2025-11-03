class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans =0;
        unordered_map<int, long long> mp;
    for (int& x: tasks) {
       ans++;
        
        if (mp.count(x) && ans - mp[x] <= space)
            ans += space - (ans - mp[x]) + 1;
        
        mp[x] =ans;
    }
    return ans;
    }
};