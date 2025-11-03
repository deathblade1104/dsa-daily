class Solution {
public:
    
    vector<int>NGE(vector<int>&nums){
        
        int n = nums.size();
        vector<int>ans(n,-1);
        
        stack<int>st;
        st.push(nums[n-1]);
        
        for(int i = n-2;i>=0;i--){
    
            while(st.size() and nums[i]>=st.top())
                st.pop();
            
            if(st.size())
                ans[i] = st.top();
            
            st.push(nums[i]);
        }
        
        return ans;
    }
    
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>v=NGE(nums2);
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums2.size();i++)
            mp[nums2[i]] = i;
        
        vector<int>ans;
        
        for(int&i : nums1)
        ans.push_back(v[mp[i]]);
        
        
        return ans;
        
        
    }
};