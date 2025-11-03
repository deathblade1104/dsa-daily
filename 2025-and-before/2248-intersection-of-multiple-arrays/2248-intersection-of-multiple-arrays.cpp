class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int count[1001];
        memset(count,0,sizeof(count));
        vector<int>ans;
        
        for(auto v : nums)
        {
            for(auto i : v)
                count[i]++;
        }
        
        
        
        for(int i=1;i<=1000;i++)
            if(count[i]==nums.size())
                ans.push_back(i);
        
        return ans;
    }
};