class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n= nums.size();
        if(n==1)
            return nums[0];
        
        stack<int>st;
        vector<int>lb(n,0),rb(n,0);
        
        st.push(0);
        lb[0]=-1;
        
        for(int i=1;i<n;i++)
        {
            while(st.size()>0 and nums[st.top()]>=nums[i])
                st.pop();
            
            if(st.size()==0)
                lb[i]=-1;
            else
                lb[i]=st.top();
            
            st.push(i);
        }
        
        while(st.size()>0)
            st.pop();
                
        st.push(n-1);
        rb[n-1]=n;
        
        for(int i=n-2;i>=0;i--)
        {
            while(st.size()>0 and nums[st.top()]>=nums[i])
                st.pop();
            
            if(st.size()==0)
                rb[i]=n;
            else
                rb[i]=st.top();
            
            st.push(i);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        { 
            int w = rb[i] - lb[i] - 1;
            ans = max(ans, (nums[i]*w));
        }
        
        return ans;
    }
};