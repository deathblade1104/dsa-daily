class Solution {
public:
    vector<int>st;
    array<int,1001>nse,pse;
    
    long long sumSubarrayMaxs(vector<int>& arr) {
        
        int n =arr.size();        
        for(int i=0;i<n;i++)
        {
            pse[i]= i+1;
            nse[i] = n - i;
        }
        
        st.clear();
        st.push_back(0);
        
        for(int i=1;i<n;i++)
        {
            while(st.size()>0 and arr[st.back()]<arr[i])
                st.pop_back();
            
            if(st.size()!=0)
                pse[i]=i - st.back();
            
            st.push_back(i);
        }
        
        st.clear();
        st.push_back(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(st.size()>0 and arr[st.back()]<=arr[i])
               st.pop_back();
            
            if(st.size()!=0)
                nse[i]=  st.back() - i;
            
            st.push_back(i);
        }
        
       long long ans= 0;
        for(int i=0;i<n;i++)
        {
            long long curr = arr[i];
            curr*=pse[i];
            curr*=nse[i];
        
            ans = ans + curr;        
        }
        
        
        return ans;   
    }
    
    
    long long sumSubarrayMins(vector<int>& arr) {
        
        int n =arr.size();        
        for(int i=0;i<n;i++)
        {
            pse[i]= i+1;
            nse[i] = n - i;
        }
        
        st.clear();
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
        
       long long ans= 0;
        for(int i=0;i<n;i++)
        {
            long long curr = arr[i];
            curr*=pse[i];
            curr*=nse[i];
        
            ans = ans + curr;        
        }
        
        
        return ans; 
    }
    
    
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
        
    }
};