class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>vis(n,false);
        
        if(start>=n)
            return false;
        
        queue<int>q;
        q.push(start);
        vis[start]=true;
        
        while(q.size()>0)
        {
            int curr=q.front();
            q.pop();
            
            if(arr[curr]==0)
                return true;
            
            int forw=curr+arr[curr],backw=curr-arr[curr];
            
            if(forw<n and vis[forw]==false)
            {
               q.push(forw);
                vis[forw]=true;
            }
            
            if(backw>=0 and vis[backw]==false)
            {
               q.push(backw);
                vis[backw]=true;
            }
        }
        
        return false;
    }
};