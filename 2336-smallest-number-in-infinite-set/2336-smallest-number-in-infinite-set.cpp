class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    unordered_set<int>vis;
    int minNum;
    SmallestInfiniteSet() {
        minNum = 1;
    }
    
    int popSmallest() {
        
        if(pq.size()){
            int x = pq.top();
            pq.pop();
            vis.erase(x);
            return x;
        }

        return minNum++;
    }
    
    void addBack(int num) {
        if(num<minNum and !vis.count(num)){
            pq.push(num);
            vis.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */