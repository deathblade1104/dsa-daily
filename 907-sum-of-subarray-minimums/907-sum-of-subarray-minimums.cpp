class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n =arr.size();
        
        stack<int>st;
        vector<int>nse(n),pse(n);
        
        for(int i=0;i<n;i++)
        {
            pse[i]= i+1;
            nse[i] = n - i;
        }
        
        st.push(0);
        
        for(int i=1;i<n;i++)
        {
            while(st.size()>0 and arr[st.top()]>arr[i])
                st.pop();
            
            if(st.size()!=0)
                pse[i]=i - st.top();
            
            st.push(i);
        }
        
        while(st.size()!=0)
            st.pop();
        
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(st.size()>0 and arr[st.top()]>=arr[i])
               st.pop();
            
            if(st.size()!=0)
                nse[i]=  abs(i- st.top());
            
            st.push(i);
        }
        
       long long int ans = 0,mod = 1e9 + 7;
        for(int i=0;i<n;i++)
        {
            long long int curr = arr[i];
            curr*=pse[i];
            curr%=mod;
            curr*=nse[i];
            curr%=mod;
            // cout<<arr[i]<<" _ "<<pse[i]<<"__"<<nse[i]<<"==="<<curr<<endl;
            
            ans = ans + curr;
            ans%=mod;
            // cout<<ans<<endl;
            
        }
        
        
        return ans;
        
    }
};