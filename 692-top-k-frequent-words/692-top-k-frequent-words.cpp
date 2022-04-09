class Solution {
public:
    struct mycomp
    {
        bool operator()(const pair<string,int>&a, const pair<string,int>&b)
        {
            if(a.second !=b.second)
                return a.second>b.second;
            
            else
                return a.first<b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        
        for(string s : words)
            mp[s]++;
        
        priority_queue<pair<string,int> , vector<pair<string,int>> , mycomp> pq;
        
        for(auto it : mp)
        {
            pq.push({it.first,it.second});
            
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<string>ans;
        
        while(pq.size()>0)
        {
            auto p = pq.top();
            pq.pop();
            
            ans.push_back(p.first);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};