class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        queue<int>pos;
        stack<int>neg;
        
        for(int i : nums)
        {
            if(i<0)
                neg.push(i);
            
            else pos.push(i);
        }
        
        vector<int>ans;
        
        while(pos.size()>0 and neg.size()>0)
        {
            if(abs(neg.top())<=pos.front())
            {
                ans.push_back(neg.top()*neg.top());
                neg.pop();
            }
            
            else
            {
                ans.push_back(pos.front()*pos.front());
                pos.pop();
            }
        }
        
        while(neg.size()>0)
        {           
            ans.push_back(neg.top()*neg.top());
            neg.pop();
        }
        
        while(pos.size()>0)
        {
            ans.push_back(pos.front()*pos.front());
            pos.pop();
        }
        
        return ans;
    }
};