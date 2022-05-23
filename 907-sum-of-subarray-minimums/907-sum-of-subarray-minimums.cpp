class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n =arr.size();
        
        vector<int>st;
        vector<int>nse(n),pse(n);
        
        for(int i=0;i<n;i++)
        {
            pse[i]= i+1;
            nse[i] = n - i;
        }
        
        st.push_back(0);
        
        for(int i=1;i<n;i++)
        {
            while(st.size()>0 and arr[st.back()]>arr[i])
                st.pop_back();
            
            if(st.size()!=0)
                pse[i]=i - st.back();
            
            st.push_back(i);
        }
        
        st.clear();
        st.push_back(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(st.size()>0 and arr[st.back()]>=arr[i])
               st.pop_back();
            
            if(st.size()!=0)
                nse[i]=  st.back() - i;
            
            st.push_back(i);
        }
        
       long long int ans = 0,mod = 1e9 + 7;
        for(int i=0;i<n;i++)
        {
            long long int curr = arr[i];
            curr*=pse[i];
            curr%=mod;
            curr*=nse[i];
            curr%=mod;
            
            ans = ans + curr;
            ans%=mod;            
        }
        
        
        return ans;
        
    }
};