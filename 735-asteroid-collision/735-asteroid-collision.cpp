class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int>ans;
        
        for(int i: arr)
        {
            int ele=i;
            
            while(ele<0 and ans.size()>0 and ans.back()>0)
            {
                int top= ans.back();
                ans.pop_back();
                
                if(top==abs(ele))
                {
                    ele=0;
                    break;
                }
                
                else if(top>abs(ele))
                    ele=top;               
                
            }
            
            if(ele!=0)
                ans.push_back(ele);
        }
        
        return ans;
        
    }
};