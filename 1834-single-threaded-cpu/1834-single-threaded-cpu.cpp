class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        
        
        for(int i=0;i<n;i++)
            tasks[i].push_back(i);
        
        
        sort(tasks.begin(),tasks.end());
        
        
        int i=0;
        long long t = tasks[0][0];
        
        vector<int>ans;
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
        
        
        while(pq.size() || i<n){
            
            
            while(i<n && t>=tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            
            
            if(pq.size() ==0 and i<n){
                 t = tasks[i][0];
            }
            
            else{
                ans.push_back(pq.top()[1]);
                t+=pq.top()[0];
                pq.pop();
            }
        }
        
        return ans;
    }
};