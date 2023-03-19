class BrowserHistory {
public:
    int curr,sz;
    
    unordered_map<int,string>mp;
    BrowserHistory(string homepage) {
        curr = sz = 1;
        mp[curr] = homepage;
    }
    
    void visit(string url) {
        
        curr++;
        sz=curr;
        
        mp[curr] = url;
        
    }
    
    string back(int steps) {
        
        curr = max(1,curr - steps);
        return mp[curr];
    }
    
    string forward(int steps) {
        curr = min(sz, curr + steps);
        return mp[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */