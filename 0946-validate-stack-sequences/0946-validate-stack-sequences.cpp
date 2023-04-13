class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        
        int i=0,j=0,n=pushed.size();
        stack<int>st;
        
        while(i<n && j<n){
            
            
            st.push(pushed[i++]);
            
            while(st.size() and popped[j] == st.top()){
                j++;
                st.pop();
            }
        }
        
        return (st.size()==0);
        
    }
};