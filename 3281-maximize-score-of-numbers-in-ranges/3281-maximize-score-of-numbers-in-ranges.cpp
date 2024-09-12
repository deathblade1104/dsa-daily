class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
         sort(begin(start), end(start));
    long long l = 0, r = start[1] + d - start[0];
    while (l < r) {
        long long m = (l + r + 1) / 2, point = start[0], i = 1;
        for (; i < start.size(); ++i) {
            point = max((long long)start[i], point + m);
            if (point > start[i] + d)
                break;
        }
        if (i == start.size())
            l = m;
        else
            r = m - 1;
    }
    return l;
    }
};