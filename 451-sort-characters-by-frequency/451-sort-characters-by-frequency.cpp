class Solution {
public:
    struct mycomp
    {
        bool operator()(const pair<int,int>&a, const pair<int,int>&b)
        {
            return a.second<b.second;
        }
    };
    
    string frequencySort(string s) {
        int mp[128];
        memset(mp,0,sizeof(mp));
        
        for(char ch : s)
            mp[ch]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp>pq;
        
        for(int i=0;i<128;i++)
        {
            if(mp[i]>0)
                pq.push({i,mp[i]});
        }
        
        s="";
        
        while(pq.size()>0)
        {            
            auto p = pq.top();
            pq.pop();
            
            while(p.second--)
            s+=(char)(p.first);
        }
        
        return s;
        
        
            
    }
};