class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int>pq;
        long long int total = 0LL;
        
        for(int&i : piles){
            total+=i;
            pq.push(i);
        }
        
        while(pq.size() and k--){
            
            int curr = pq.top();
            pq.pop();
            
            int x = floor(curr/2);
            curr-=x;
            total-=x;
            if(curr)
                pq.push(curr);
        }
        
        return (int)total;
        
    }
};