class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>suffix(n,-1);
        suffix[n-1] = nums.back();
    
        for(int i=n-2;i>=0;i--)
        suffix[i] = max(nums[i],suffix[i+1]);
        
        set<int>st;
        st.insert(nums[0]);
        
        for(int i=1;i<n-1;i++){
            st.insert(nums[i]);
            
            auto it = st.find(nums[i]);
            
            if(it == st.begin())
                continue;
            
            int op1 = *--it, op2=suffix[i];
            
            if(op1<nums[i] and nums[i]<op2)
            {
                // cout<<op1<<" "<<nums[i]<<" "<<op2<<endl;
                return true;
            }
        }
        
        return false;
        
    }
};