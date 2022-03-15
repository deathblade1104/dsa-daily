class Solution {
public:
    int maximumTop(vector<int>&nu, int k) {
        if(k==0)
            return nu[0];
       
        if(nu.size()==1)
        {
            if(k%2==0)
                return nu[0];
            
            else return -1;
        }
        
        int m=INT_MIN;
        stack<int>st;
        
        for(int i= nu.size()-1;i>=0;i--)
            st.push(nu[i]);        
        
        while(k>1)
        {
            m=max(m,st.top());
            st.pop();
            k--;
            
            if(st.size()==0)
                break;
        }
        
        if(st.size()==0)
        return m;
        
        else if(k==1 and st.size()>=2)
        {
            st.pop();
            m=max(m,st.top());
            st.pop();
        }
            
        
        return m;
        
        
    }
};