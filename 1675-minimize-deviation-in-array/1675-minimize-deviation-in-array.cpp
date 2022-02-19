class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
                nums[i]=nums[i]*2;
                
        }
        
        multiset<int,greater<int>>st(nums.begin(),nums.end());
        
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