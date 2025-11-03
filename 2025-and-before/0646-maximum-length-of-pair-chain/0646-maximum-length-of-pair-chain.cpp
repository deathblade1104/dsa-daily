class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> lis;

        for(auto& it: pairs){
            auto idx = lower_bound(lis.begin(), lis.end(), it[0]);
            if(idx==lis.end()) lis.push_back(it[1]);
            else *idx = min(*idx, it[1]);
        }

        return lis.size();
        
    }
};