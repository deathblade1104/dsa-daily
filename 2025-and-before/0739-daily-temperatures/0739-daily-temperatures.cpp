class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>s;
        int n = temp.size();
        vector<int>ans(n,0);
        
        s.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(s.size()>0 and temp[s.top()]<=temp[i])
            s.pop();
            
            if(s.size()!=0)
                ans[i]=(s.top()-i);
            
            s.push(i);
        }
                    
        return ans;
        
    }
};