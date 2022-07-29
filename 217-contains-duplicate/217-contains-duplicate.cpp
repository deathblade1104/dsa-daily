class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        
        for(int i : nums)
        {
            if(st.count(i))
                return true;
            
            st.insert(i);
        }
        
        return false;
    }
};