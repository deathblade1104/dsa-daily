class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        st.push(-1);
        
        for(int i=0;i<num.size();i++)
        {
            int x = num[i] - '0';
            
            while(x<st.top() and st.size()>1 and k!=0)
            {
                k--;
                st.pop();
            }
            
            st.push(x);
        }
        
        while(k!=0 and st.size()>1)
        {
            k--;
            st.pop();
        }
        
        string ans="";
        
        while(st.size()>1)
        {
            ans+=to_string(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<" ";

        if(ans[0]=='0' and ans.size()!=1)
        {
            int i=0;
            while(ans[i]=='0')
                i++;
            
            ans=ans.substr(i);
        }
        
        if(ans=="")
            return "0";
        
        return ans;
        
        
        
    }
};