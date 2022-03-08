class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<pair<int,int>>st;
        
        for(int i=0;i<arr.size();i++)
        {
            int nv=abs(arr[i]),s=0;            
            if(arr[i]>0)
                s=+1;
            
            if(arr[i]<0)
                s-=1;
            
            
            while(st.size() and s==-1 and s!=st.top().first)
            {
                pair<int,int>p=st.top();
                st.pop();
                
                if(abs(nv)!=abs(p.second))
                {
                    nv=max(abs(nv),abs(p.second));
                    
                    if(abs(nv)!=abs(arr[i]))
                     s=p.first;
                }
                
                else
                {
                    nv=0;
                    break;
                }                 
            }
            
            if(nv!=0)
                st.push({s,nv});
        }
        
        vector<int>ans;
        while(st.size())
        {
            pair<int,int>p=st.top();
            st.pop();
            
            ans.push_back(p.first*p.second);            
        }
        
        reverse(ans.begin(),ans.end());        
        return ans;
        
    }
};