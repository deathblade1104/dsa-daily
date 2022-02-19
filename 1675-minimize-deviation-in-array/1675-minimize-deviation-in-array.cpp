class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        multiset<int,greater<int>>st;        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
                st.insert(nums[i]*2);
            
            else
                st.insert(nums[i]);                
        }
        
        int ans = *(st.begin()) - *(st.rbegin());
        
        while(*st.begin()%2==0)
        {
            int val=*st.begin();
            st.erase(val);
            st.insert(val/2);
            
            ans= min(ans, (*(st.begin()) - *(st.rbegin())));
        }
        
        return ans;
        
        
        
        
        
        
    }
};