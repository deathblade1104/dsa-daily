class Solution {
public:
    
    vector<string> buildArray(vector<int>& target, int n) {
        
        int sz = target.size();
        vector<string>ans;
        stack<int>st;
        int j = 0,k=0;
        
        for(int i=1;j<sz and i<=n;i++){
            
            if(target[j] == i){
                int prevEle = j-1>=0 ? target[j-1]  : -1;
                
                while(st.size() and st.top()>prevEle){
                    st.pop();
                    ans.push_back("Pop");
                }
                j++;
            }
            
            st.push(i);
            ans.push_back("Push");
        }
        
        return ans;
        
    }
};