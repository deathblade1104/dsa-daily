class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        
        unordered_map<int,pair<long long,int>>mp;
        long long curr =0;
        vector<long long>res;
        
        for (int i=removeQueries.size()-1;i>=0;i--){
            int q = removeQueries[i];
            
            mp[q] = {nums[q], 1};
            
            pair<long long,int> dummy = make_pair(0L,0);
            auto p = mp.count(q+1)==1 ? mp[q+1] : dummy;
            long long rv = p.first;
            int rLen = p.second;
            
            
            p = mp.count(q-1) ==1 ? mp[q-1] : dummy;
            long long lv = p.first;
            int lLen = p.second;
            
                
            long long total = nums[q] + rv + lv;
            mp[q+rLen] = {total, lLen + rLen + 1};
            mp[q-lLen] = {total, lLen + rLen + 1};
        
            curr = max(curr, total);
            res.push_back(curr);
        }
        
        res.pop_back();
        reverse(res.begin(),res.end());
        res.push_back(0);
        
        return res;
        
    }
};