class Solution {
public:
    typedef array<int,2> arr;
    bool vis[100002];
    long long findScore(vector<int>& nums) {
        
        priority_queue<arr,vector<arr>,greater<arr>>pq;
        memset(vis,0,sizeof vis);
        
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});    
        }
        
        long long ans = 0LL;
        
        while(pq.size()){
            
            arr curr = pq.top();
            pq.pop();
            
            if(vis[curr[1]])
                continue;
            
            ans+=curr[0];
            
            vis[curr[1]] = true;
            
            if(curr[1] - 1>=0)
                vis[curr[1] - 1] = true;
            
            vis[curr[1] + 1] = true;
        }
        
        return ans;
        
    }
};