class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        if(indexDiff==0)
            return false;
        
        
        vector<array<int,2>>v;
        
        for(int i=0;i<nums.size();i++)
            v.push_back({nums[i],i});
        
        sort(v.begin(),v.end());
        
        int start=0;
        unordered_set<int>st;
        
        
        for(int i=0;i<v.size();i++){
            
            int curr = v[i][0];
            
            while(curr - v[start][0]>valueDiff){
                int idx = v[start][1];
                st.erase(idx);
                start++;
            }
            
            for(int x :st)
                if(abs(x - v[i][1])<=indexDiff)
                    return true;
            
            st.insert(v[i][1]);
        }
        
        return false;
    }
};