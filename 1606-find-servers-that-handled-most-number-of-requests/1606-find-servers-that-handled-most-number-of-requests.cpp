class Solution {
public:
    int count[(int)(1e5) + 1];
    priority_queue<array<long long,2>,vector<array<long long,2>>,greater<array<long long,2>>>pq;
    set<int>st;
    
    void insert(int x,int&arr,int&load){
        st.erase(x);
        count[x]++;
        
        pq.push({arr+load,x});
        return;
    }
    
    vector<int>getMax(int k){
        
        int res=-1;
        vector<int>ans;
        
        for(int i=0;i<k;i++){
            
            if(count[i]>res){
                ans.clear();
                res = count[i];
            }
            
            if(count[i] == res){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        memset(count,0,sizeof count);
        
        for(int i=0;i<k;i++){
            st.insert(i);
        }
        
        for(int i=0;i<arrival.size() and i<k;i++)
            insert(i,arrival[i],load[i]);
            
        
        for(int i=k;i<arrival.size();i++){
            
            while(pq.size() and pq.top()[0]<=arrival[i]){
                st.insert(pq.top()[1]);
                pq.pop();
            }
            
            if(st.size() == 0)
                continue;
            
            auto server = st.lower_bound(i%k);
            
            if(server == st.end())
                server = st.begin();

            insert(*server,arrival[i],load[i]);
            
        }
        
        return getMax(k);
    }
};