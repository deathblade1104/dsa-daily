class Solution {
public:
    int par[26];
    
    int findPar(int p){
        
        if(par[p] == p)
            return p;
        
        return par[p] = findPar(par[p]);
    }
    
    void Disunion(int v1,int v2){
        int p1 = findPar(v1),p2 = findPar(v2);
        
        if(p1<=p2){
            par[p2] = p1;
        }
        
        else{
            par[p1] = p2;
        }
        
        return;
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        for(int i=0;i<26;i++)
            par[i]=i;
        
        for(int i=0;i<s1.size();i++){
            int c1 = s1[i] -'a', c2 = s2[i] - 'a';
            
            if(c1!=c2){
                Disunion(c2,c1);                
            }
        }
        
        string ans="";
        
        for(char&ch : baseStr){
            int p = findPar(ch - 'a');
            
            ans+=(char)(p + 'a');
        }
        
        return ans;
        
    }
};