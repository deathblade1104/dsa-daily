class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    bool added[1001];
    int minNum;
    
    SmallestInfiniteSet() {
        minNum = 1;
        memset(added,0,sizeof added);
    }
    
    int popSmallest() {
        
        if(pq.size()){
            int x = pq.top();
            pq.pop();
            added[x] = false;
            return x;
        }

        return minNum++;
    }
    
    void addBack(int num) {
        if(num<minNum and !added[num]){
            pq.push(num);
            added[num] = 1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */