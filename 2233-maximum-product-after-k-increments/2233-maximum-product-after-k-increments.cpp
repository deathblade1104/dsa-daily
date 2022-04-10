class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        
        while(k--)
        {
            int x = pq.top();
            pq.pop();
            x++;
            pq.push(x);
        }
        
        long long int ans=1LL, m= 1e9 +7;
        
        while(pq.size()>0)
        {
            int x = pq.top();
            pq.pop();
            ans= ((ans%m) * (x%m))%m;
        }
        
        return ans;
    }
};