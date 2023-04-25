class SmallestInfiniteSet {
public:
    bool added[1001];
    SmallestInfiniteSet() {
        memset(added,1,sizeof added);
    }
    
    int popSmallest() {
        
        for(int i=1;i<1001;i++){
            if(added[i]){
                added[i] = false;
                return i;
            }
        }
        
        return -1;
    }
    
    void addBack(int num) {
        added[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */