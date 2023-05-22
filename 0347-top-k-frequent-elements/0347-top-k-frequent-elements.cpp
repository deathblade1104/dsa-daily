class Solution {
public:
    
    int pos[10001],neg[10001];
    vector<int> topKFrequent(vector<int>& nums, int k) {
        memset(pos,0,sizeof pos);
        memset(neg,0,sizeof neg);
        
        for(int&i : nums){
            
            if(i>=0)
                pos[i]++;
            
            else
                neg[abs(i)]++;
        }
        
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
        
        for(int i=0;i<10001;i++){
            pq.push({pos[i],i});
            
            if(pq.size()>k)
                pq.pop();
            
            pq.push({neg[i],-i});
            
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<int>ans;
        
        while(pq.size()){
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        
        return ans;
        
    }
};