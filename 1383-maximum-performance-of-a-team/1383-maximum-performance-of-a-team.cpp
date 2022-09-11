class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<array<int,2>>v;
        
        for(int i=0;i<n;i++)
            v.push_back({efficiency[i],speed[i]});
        
        sort(v.begin(),v.end(),greater<array<int,2>>());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        long long ans=0, curr=0,speedSum=0, mod = 1e9 + 7;
        
        for(auto&p : v){
        
            pq.push(p[1]);
            speedSum+=p[1];
            
            while(pq.size()>k){
                speedSum-=pq.top();
                pq.pop();
            }
            
            curr = (speedSum* p[0]);
            
            ans = max(ans,curr);
        }
        
        
        return ans%mod;
    }
};