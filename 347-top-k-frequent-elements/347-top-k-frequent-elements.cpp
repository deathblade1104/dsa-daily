class Solution {
public:
    struct mycomp
    {
        bool operator()(const pair<int,int>&a, const pair<int,int>&b)
        {
            return a.second>b.second;   
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        for(int i : nums)
            mp[i]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycomp>pq;
        
        for(auto it : mp)
        {
            pq.push({it.first, it.second});
            
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<int>ans;
        while(pq.size()!=0)
        {
            auto p = pq.top();
            pq.pop();
            
            ans.push_back(p.first);
        }
        
        return ans;
        
        
    }
};