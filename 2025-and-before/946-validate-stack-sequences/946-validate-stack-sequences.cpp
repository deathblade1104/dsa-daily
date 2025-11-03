class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0;
        for(int x : pushed)
        {
            st.push(x);
            while(st.size()>0 and popped[i]==st.top())
            {
                st.pop();
                i++;
            }
        }
        
        return (st.size()==0);
    }
};