class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_set<int>st;
        int pairs = 0;
        
        for(int&i : nums){
            
            if(st.count(i)==1){
                st.erase(i);
                pairs++;
            }
            
            else st.insert(i);
        }
        
        vector<int>ans={pairs,(int)st.size()};
        
        return ans;
    }
};