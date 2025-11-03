class Solution {
public:
    int n;
    vector<int>prev,next;
    stack<int>st;
    int sumSubarrayMins(vector<int>& nums) {
        n =nums.size();
        
        prev.resize(n);
        next.resize(n);
        
        
        for(int i=0;i<n;i++){
            prev[i] =i+1;
            next[i] = n - i;
        }
        
        st = stack<int>();
        st.push(0);
        
        for(int i=1;i<n;i++){
            
            while(st.size() and nums[st.top()]>nums[i])
                st.pop();
            
            if(st.size())
                prev[i] = i - st.top();
            
            st.push(i);
        }
        
        st = stack<int>();
        st.push(n-1);
            
        for(int i=n-2;i>=0;i--){
            
            while(st.size() and nums[st.top()]>=nums[i])
                st.pop();
            
            if(st.size())
                next[i] = st.top() -i;
            
            st.push(i);
        }
        
        
        long long ans = 0LL,mod = 1e9 + 7;
        
        for(int i=0;i<n;i++){
            long long int curr = 1LL * nums[i];
            curr*=prev[i];
            curr%=mod;
            curr*=next[i];
            curr%=mod;
            
            ans+=curr;
            ans%=mod;    
        }
        
        return ans;
    }
};