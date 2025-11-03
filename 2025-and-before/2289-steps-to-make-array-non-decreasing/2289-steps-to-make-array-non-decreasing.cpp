class Solution {
public:
    int totalSteps(vector<int>& nums) {
         
        if(nums.size()==0 or nums.size()==1)
            return 0;
        
        int sz = nums.size() -1,ans = 0;
        stack<array<int,2>>st;
        st.push({nums[sz],0});
        
        for(int i = sz-1;i>=0;i--)
        {
            int count =0;    
            while(st.size()!=0 and nums[i]>st.top()[0])
            {
                count = max(count+1, st.top()[1]);
                st.pop();
            }
            
            ans = max(ans , count);
            st.push({nums[i],count});
        }
        
        return ans;
    }
};