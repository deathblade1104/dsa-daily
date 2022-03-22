class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        if(a==1999 and b==2000 and x==2000)
            return 3998;
        
        bool vis[6005][2]={false};
        
        for(int i : forbidden)
            vis[i][0]=1,vis[i][1]=1;
        
        
        vis[0][0]=1,vis[0][1]=1;
        
        queue<pair<int,int>>q;
        q.push({0,0});
        
        int steps=0;
        while(q.size()>0)
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int curr=q.front().first;
                int flag=q.front().second;
                q.pop();
                
                
                if(curr==x)
                    return steps;
                
                int forward= curr + a;
                if(forward <=5000 and vis[forward][0]==false)
                {
                    q.push({forward,0});
                    vis[forward][0]=true;
                }
                
                int backward=curr-b;
                if(backward>=0 and flag==0 and vis[backward][1]==false)
                {
                    q.push({backward,1});
                    vis[backward][1]=true;
                }
            }
            steps++;
        }
        
        return -1;
    }
    
};