// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
private:
struct Node{
    int r,c,times;
    
    Node(int x, int y, int z)
    {
        r=x;
        c=y;
        times=z;
    }
};

public:

    int helpaterp(vector<vector<int>> grid)
    {
        //code here
        int n=grid.size(), m=grid[0].size(),ans=INT_MIN, count=0;
        queue<Node>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                count++;
                
                else if(grid[i][j]==2)
                {
                    Node temp(i,j,0);
                    q.push(temp);
                }
            }
        }
        
        if(q.size()==0 and count>0)
        return -1;
        
        while(q.size() and count)
        {
            Node t=q.front();
            q.pop();
            
            if(t.r<0 or t.r>=n or t.c<0 or t.c>=m or grid[t.r][t.c]==0)
            continue;
            
            if(grid[t.r][t.c]==1)
            count--;
            
            ans=max(ans,t.times);
            
            grid[t.r][t.c]=0;
            
            
            Node t1(t.r+1,t.c,t.times+1);
            q.push(t1);
            
            Node t2(t.r-1,t.c,t.times+1);
            q.push(t2);
            
            Node t3(t.r,t.c+1,t.times+1);
            q.push(t3);
            
            Node t4(t.r,t.c-1,t.times+1);
            q.push(t4);
        }
        
        if(count!=0)
        return -1;
        
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends