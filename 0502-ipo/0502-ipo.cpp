class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<array<int,2>>arr;
        for(int i=0;i<capital.size();i++){
            arr.push_back({capital[i],profits[i]});
        }
        
        sort(arr.begin(),arr.end());
        
        int i=0;
        priority_queue<int>pq;
        
        while(k--){
            
            while(i<arr.size() and arr[i][0]<=w){
                pq.push(arr[i][1]);
                i++;
            }
            
            if(pq.size() == 0)
                break;
            
            w+=pq.top();
            pq.pop();
        }
        
        return w;
    }
};