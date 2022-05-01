class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());
        
        while(pq.size()>=2)
        {
            int x = pq.top(); pq.pop();
            int y = pq.top();pq.pop();
            
            if(x-y!=0)
                pq.push(x-y);
        }
        
        if(pq.size()==1)
            return pq.top();
        
        return 0;
    }
};