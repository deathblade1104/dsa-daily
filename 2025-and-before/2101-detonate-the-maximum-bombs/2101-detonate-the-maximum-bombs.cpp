class Solution {
public:
    int dfs(int i, vector<vector<int>> &al, bitset<100> &detonated) {
    if (!detonated[i]) {
        detonated[i] = true;
        for (int j : al[i])
            dfs(j, al, detonated);
    }
    return detonated.count();
}
int maximumDetonation(vector<vector<int>>& bs) {
    int res = 0, sz = bs.size();
    vector<vector<int>> al(bs.size());
    for (int i = 0; i < sz; ++i) {
        long long x = bs[i][0], y = bs[i][1], r2 = (long long)bs[i][2] * bs[i][2];
        for (int j = 0; j < bs.size(); ++j)
            if ((x - bs[j][0]) * (x - bs[j][0]) + (y - bs[j][1]) * (y - bs[j][1]) <= r2)
                al[i].push_back(j);
    }
    for (int i = 0; i < sz && res < sz; ++i)
        res = max(dfs(i, al, bitset<100>() = {}), res);
    return res;
}
};