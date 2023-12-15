class Solution {
public:
    unordered_map<string,string>mp;
    
    string DFS(string curr){
        
        if(!mp.count(curr)){
            return curr;
        }
        
        return DFS(mp[curr]);
    }
    
    string destCity(vector<vector<string>>& paths) {
        
        for(auto&vec : paths)
            mp[vec[0]] = vec[1];
        
        
        return DFS(paths[0][0]);
    }
};