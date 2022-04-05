class Solution {
public:
    int find_par(int x, vector<int>&par)
    {
        if(par[x]==x)
            return x;
        
        return par[x]= find_par(par[x],par);
    }
    
    void DSUnion(int n1,int n2,vector<int>&par, vector<int>&rank)
    {
        int p1=find_par(n1,par), p2= find_par(n2,par);
        
        if(p1==p2)
            return;
        
        if(rank[p1]>rank[p2])
            par[p2]=p1;
        
        else if (rank[p2]>rank[p1])
            par[p1]=p2;
        
        else
        {
            rank[p1]++;
            par[p2]=p1;
        }
        return;
    }
    
    bool equationsPossible(vector<string>& equations){
        
        vector<int>par(26),rank(26,0);               
        for(int i=0;i<26;i++)
            par[i]=i;
        
        for(auto itr : equations)
        {
            int n1=(int)(itr[0]-'a'),n2=(int)(itr[3]-'a');
                    
            if(itr[1]=='=')
                DSUnion(n1,n2,par,rank);     
           
        }
        
        for(auto itr : equations)
        {
            int n1=(int)(itr[0]-'a'),n2=(int)(itr[3]-'a'),p1= find_par(n1,par), p2 = find_par(n2,par);
                                
            if(itr[1]=='!' and p1==p2)
                return false;            
        }
        
        return true;
    }
};