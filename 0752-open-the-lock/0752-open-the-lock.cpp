class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<bool>vis(10000,false);
        
        for(int i=0;i<deadends.size();i++)
        {
            int num=stoi(deadends[i]);
            vis[num]=true;
        }
        
        if(vis[0] or vis[stoi(target)])
            return -1;
        
        queue<string>q;
        q.push("0000");
        vis[0]=true;
        int steps=0;
        
        while(q.size()>0)
        {
            int sz=q.size();
            
            for(int i=0;i<sz;i++)
            {
                string curr= q.front();
                q.pop();

                if(curr==target)
                    return steps;
                
                for(int j=0;j<4;j++)
                {
                    string left = curr.substr(0,j), right=curr.substr(j+1);
                    int num = curr[j] -'0',n1,n2;
                    
                    if(num==9)
                    {
                        n1=0;
                        n2=8;
                    }
                    
                    else if(num==0)
                    {
                        n1=1;
                        n2=9;
                    }
                    
                    else
                    {
                        n1=num-1;
                        n2=num+1;
                    }
                    
                    char ch1 = (char)(n1+ '0');
                    
                    string temp1 = left;
                    temp1+=ch1;
                    temp1+=right;
                    
                    char ch2 = (char)(n2 + '0');
                    
                    string temp2 = left;
                    temp2+=ch2;
                    temp2+=right;
                    
                    int num1=stoi(temp1),num2=stoi(temp2);
                    
                    if(vis[num1]==false)
                    {
                        vis[num1]=true;
                        q.push(temp1);
                    }
                    
                    if(vis[num2]==false)
                    {
                        vis[num2]=true;
                        q.push(temp2);
                    }
                }
                
            }
            steps++;
        }
        
        return -1;
        
    }
};