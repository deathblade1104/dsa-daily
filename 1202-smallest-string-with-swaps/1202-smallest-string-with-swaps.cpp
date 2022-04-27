class Solution {
public:
    int get_par(int p, vector<int>&par)
    {
        if(p== par[p])
            return p;
        
        return par[p] = get_par(par[p],par);
    }
    
    void DSUnion (int n1, int n2, vector<int>&par, vector<int>&rank)
    {
        int p1= get_par(n1,par) , p2 = get_par(n2,par);
        
        if(p1==p2)
            return;
        
        if(rank[p1]>=rank[p2])
        {
            rank[p1]++;
            par[p2]=p1;
        }
        
        else
        {
            rank[p2]++;
            par[p1]=p2;
        }
        
        return;
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n=s.size();
        vector<int>par(n),rank(n,0);
        
        for(int i=0;i<n;i++)
            par[i]=i;
        
        for(auto p : pairs)
            DSUnion(p[0],p[1],par,rank);
        
        vector<vector<int>>mp(s.size());
        
        for(int i=0;i<s.size();i++)
        mp[get_par(i,par)].push_back(i);
        
        
        
        for(auto v : mp)
        {
            string temp="";
            for(int i=0;i<v.size();i++)
                temp+=s[v[i]];
            
            sort(temp.begin(), temp.end());
            
            int j=0;
            for(int i=0;i<v.size();i++)
                s[v[i]]=temp[j++];
        }
        
        
        
        return s;
        
        
        
        
    }
};