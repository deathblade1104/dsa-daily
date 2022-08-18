class Solution {
public:
    
    struct mycomp{
        bool operator()(const array<int,2>&a, const array<int,2>&b){
            return a[1]<b[1];
        }
    };
    
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        
        for(int&i : arr)
            mp[i]++;
            
        priority_queue<array<int,2>,vector<array<int,2>>,mycomp>pq;
        
        for(auto&it : mp)
            pq.push({it.first,it.second});
        
        
        int required = arr.size()/2;
        while(required>0 and pq.size()>0){
            auto p = pq.top();
            pq.pop();
            
            required-= p[1];
        }
        
        return mp.size() - pq.size();
        
    }
};