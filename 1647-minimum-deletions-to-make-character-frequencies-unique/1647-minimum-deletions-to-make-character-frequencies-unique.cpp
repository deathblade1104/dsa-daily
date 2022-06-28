class Solution {
public:
    int minDeletions(string s) {
    int cnt[26] = {}, res = 0;
    for (char ch : s)
        ++cnt[ch - 'a'];
    sort(begin(cnt), end(cnt));
    for (int i = 24; i >= 0 && cnt[i] > 0; --i) {
        res += max(0, cnt[i] - max(0, cnt[i + 1] - 1));
        cnt[i] = min(cnt[i], max(0, cnt[i + 1] - 1));
    }
    return res;
        
    }
};