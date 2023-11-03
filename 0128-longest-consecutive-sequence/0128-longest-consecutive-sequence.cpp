class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        
        int ans = 0;
        for(int&i : nums){
            
            if(st.count(i-1) == 0){
                
                int curr=1;
                while(st.count(i+curr) == 1)
                    curr++;
                
                ans = max(ans,curr);
            }
        }
        
        return ans;
        
    }
};