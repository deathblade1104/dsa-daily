class Solution {
public:
    struct mycomp{
        
        bool operator()(const pair<int,string>&a,const pair<int,string>&b){
            
            if(a.first==b.first)
                return a.second<b.second;
            
            return a.first>b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int K) {
        unordered_map<string,int>mp;
        
        for(string&s : words)
            mp[s]++;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,mycomp>pq;
        
        for(auto itr : mp){
            
            pq.push(make_pair(itr.second,itr.first));
            
            if(pq.size()>K)
                pq.pop();
        }
        
        
        vector<string>ans;
        
        while(pq.size()){
            
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};