class Solution {
public:

    void DFS(string email, unordered_set<string>&st,vector<string>&temp, unordered_map<string, vector<string>>&edges)
    {
        temp.push_back(email);
        st.insert(email);
        
        for(auto e : edges[email])
        {
            if(st.count(e)==0)
                DFS(e,st,temp,edges);
        }
        
        return;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string>dir;
        unordered_map<string,vector<string>>edges;
        unordered_set<string>st;
        vector<vector<string>>ans;
                
        for(auto v : accounts)
        {
            dir[v[1]]=v[0];
            
            for(int i=2;i<v.size();i++)
            {
                edges[v[i]].push_back(v[1]);
                edges[v[1]].push_back(v[i]);
            }            
        }
        
        for(auto it : dir)
        {
            string name = it.second, email = it.first;
          
            if(st.count(email)==0)
            {
                vector<string>temp;
                temp.push_back("");
                
                DFS(email,st,temp,edges);
                sort(temp.begin(),temp.end());
                temp[0]=name;
                ans.push_back(temp);
            }
        }
        
        return ans;
        
    }
};