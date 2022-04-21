class Solution {
public:
    string get_par(string x, unordered_map<string,string>&par)
    {
        if(x==par[x])
            return x;
        
        return par[x]= get_par(par[x],par);
    }
    
    void DSUnion(string n1, string n2, unordered_map<string,string>&par, unordered_map<string,int>&rank)
    {
        string p1 = get_par(n1,par) , p2= get_par(n2,par);
        
        if(p1==p2) return;
        
        if(rank.count(p1)==0)
            rank[p1]=0;
        
        if(rank.count(p2)==0)
            rank[p2]=0;
        
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
    }
    
    bool isSimilar(string &s1, string &s2)
    {
        int i=0,j=0,count=0;
        
        while(i<s1.size())
        {
            if(s1[i++]!=s2[j++])
                count++;
        }
        
        return (count==2);
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        unordered_map<string,string>par;
        unordered_map<string,int>rank;
        unordered_set<string>st;
        
        for(int i=0;i<strs.size();i++)
        {
            par[strs[i]]=strs[i];            
            for(int j=0;j<i;j++)
            {
                if(isSimilar(strs[i],strs[j]))
                    DSUnion(strs[i],strs[j],par,rank);
            }
        }        

        for(string s : strs)
            st.insert(get_par(s,par));
        
        return st.size();
        
    }
};