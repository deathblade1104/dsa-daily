class Bitset {
public:
    string normal="",anti="";
    int sz=0,co;
    Bitset(int size) {
        sz=size;
        
        for(int i=0;i<sz;i++)
        {
            normal+="0";
            anti+="1";
        }
        co=0;
        
    }
    
    void fix(int idx) {
        if(idx<sz and normal[idx]!='1')
        {
            normal[idx]='1';
            anti[idx]='0';
            
            co++;
        }
        
    }
    
    void unfix(int idx) {
        
        if(idx<sz and normal[idx]=='1')
        {
            normal[idx]='0';
            anti[idx]='1';
            
            co--;
        }
    }
    
    void flip() {
        swap(normal,anti);  
        
        co=sz-co;
        
    }
    
    bool all() {
        
        return(co==sz);
        
    }
    
    bool one() {
        return (co>=1);
    }
    
    int count() {
        return co;
    }
    
    string toString() {
        return normal;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */