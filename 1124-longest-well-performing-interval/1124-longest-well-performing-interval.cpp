class Solution {
public:
    int pref[100002];
    int n;
    int longestWPI(vector<int>& arr) {
        memset(pref,0,sizeof pref);
        n = arr.size();
        
        for(int i=1;i<=n;i++){
            pref[i] = arr[i-1]>8? 1 : -1;
            pref[i]+=pref[i-1];
            
        }
                
        stack<int>st;
        for(int i=0;i<=n;i++){
           
            if(st.size() == 0 || pref[st.top()]>pref[i])
                st.push(i);
        }
        
        
        int ans = 0;
        
        for(int j=n;j>=0;j--){
            
            while(st.size() and pref[st.top()]<pref[j]){
               
                ans = max(ans, j - st.top());
                st.pop();
            }
        }
        
        return ans;
        
    }
};