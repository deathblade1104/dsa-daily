typedef array<int,2> arr;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<arr>v;
        
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        
        sort(v.rbegin(),v.rend());
        
        long long ans = 0, currSum =0;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        const int mod = 1e9 + 7;
        
        for(auto&itr : v){
            
            currSum+=(itr[1]*1LL);
            pq.push(itr[1]);
            
            while(pq.size()>k){
                currSum-=pq.top();
                pq.pop();
            }
            
            
            ans= max(ans,(1LL * itr[0] *currSum));
            
        }
        
        return (int)(ans%mod);
    }
};