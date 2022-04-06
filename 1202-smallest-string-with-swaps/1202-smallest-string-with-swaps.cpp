class Solution {
public:
    int find_par(int x, vector<int>&par)
    {
        if(x==par[x])
            return x;
        
        return par[x] =  find_par(par[x],par);        
    }
    
    void DSUnion( int n1, int n2, vector<int>&par, vector<int>&rank)
    {
        int p1 = find_par(n1,par) , p2= find_par(n2,par);
        
        if(p1==p2) return;
        
        if(rank[p1]>=rank[p2])
        {
            par[p2]=p1;
            rank[p1]++;
        }
        
        else
        {
            par[p1]=p2;
            rank[p2]++;
        }
        return;
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int>par(s.size()),rank(s.size(),0);
        
        for(int i=0;i<s.size();i++)
            par[i]=i;
        
        for(auto p : pairs)
            DSUnion(p[0],p[1],par,rank);
        
        vector<vector<int>>mp(s.size());
        
        for(int i=0;i<s.size();i++)
        mp[find_par(i,par)].push_back(i);
        
        
        
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