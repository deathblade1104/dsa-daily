class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        
        unordered_map<int,int>mp;
        
        for(int&i : nums)
            mp[i]++;
        
        set<int>st(nums.begin(),nums.end());
        
        int ans = 0;
        while(st.size()>1){
            
            auto it = prev(st.end());
            int m1 = *it;
            
            auto it2 = prev(it);
            int m2 = *it2;
            
            ans+=mp[m1];
            mp[m2]+=mp[m1];
            
            st.erase(it);
            mp.erase(m1);
        }
        
        return ans;
    }
};