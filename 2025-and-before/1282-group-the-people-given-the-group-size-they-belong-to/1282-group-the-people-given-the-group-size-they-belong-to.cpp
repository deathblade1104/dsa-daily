class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& vec) {
            
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<vec.size();i++){
            mp[vec[i]].push_back(i);
        }
        
        vector<vector<int>>ans;
        
        for (auto& it : mp) {
            
            int sz = it.first;
            
            if(it.second.size() == sz)
                ans.push_back(it.second);
            
            else{
                
                vector<int>curr;
                
                while(it.second.size()){
                    curr.push_back(it.second.back());
                    it.second.pop_back();
                    
                    
                    if(curr.size() == sz){
                        ans.push_back(curr);
                        curr.clear();
                    }
                }
            }
        }
        
        return ans;
        
        
    }
};