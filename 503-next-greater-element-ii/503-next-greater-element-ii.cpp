class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n= nums.size();
        
        stack<int>st;
        vector<int>ans(n,-1);
        
        int j=n-1;
        
        while(j>=0)
            st.push(nums[j--]);
        
        for(int i=n-1;i>=0;i--){
            
            while(st.size() and st.top()<=nums[i])
                st.pop();
            
            if(st.size())
                ans[i] = st.top();
            
            st.push(nums[i]);
        }
        
        return ans;
    }
};