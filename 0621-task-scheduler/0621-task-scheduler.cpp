class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        
        int cnt[26];
        memset(cnt,0,sizeof cnt);
        
        for(char&ch : tasks){
            cnt[ch - 'A']++;
        }
        
        priority_queue<int>pq;
        
        for(int i=0;i<26;i++){
            
            if(!cnt[i])
                continue;
            
            pq.push(cnt[i]);
        }
        
        stack<int>st;
        int ans = 0;
       while(pq.size()){
           
           int sz  = n+1;
           
           
           while(sz and pq.size()){
               
               int curr = pq.top();
               pq.pop();
             
               ans++;
               --sz;
               
               //cout<<ans<<" "<<curr<<endl;
               
               if(curr>1)
                st.push(curr - 1);
           }
           
           
           while(st.size()){
               pq.push(st.top());
               st.pop();
           }
           
           if(!pq.size())
               break;
           
           ans+=sz;
        
       }
        
        return ans;
    }
};