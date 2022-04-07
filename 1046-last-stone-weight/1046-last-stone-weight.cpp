class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>pq(stones.begin(),stones.end());
        
        while(pq.size()>1)
        {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            
            if(x==y)
            {
                if(pq.size()==0)
                    return 0;
                
                else continue;
            }
            
            else pq.push(abs(x-y));
        }
        
        return pq.top();
        
    }
};