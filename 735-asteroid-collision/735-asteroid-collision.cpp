class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int>ans;
        
        for(int i: arr)
        {
            int ele=i;
            if(ele>0)
                ans.push_back(ele);
            
            else
            {
                while(ans.size() and ans.back()>0 and ans.back()<abs(ele))
                    ans.pop_back();
                if(ans.size()==0 or ans.back()<0)
                    ans.push_back(ele);
                else if(ans.back()==abs(ele))
                    ans.pop_back();                   
                    
            }
        }
        
        return ans;
        
    }
};