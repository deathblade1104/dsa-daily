class Solution {
public:
    struct mycomp
    {
        bool operator()(const pair<int,int>&a , const pair<int,int>&b)
        {
            if(a.second!=b.second)
            return a.second<b.second;
            
            return a.first<b.first;
        }
    };
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, mycomp>pq;
        vector<int>ans;
        
        for(int i : arr)
        {
            pq.push({i,abs(i-x)});
            
            if(pq.size()>k)
                pq.pop();
        }
        
        while(pq.size()>0)
        {
            auto p = pq.top();
            pq.pop();
            
            ans.push_back(p.first);
        }
        
        
        sort(ans.begin(),ans.end());
        return ans;    
        
    }
};