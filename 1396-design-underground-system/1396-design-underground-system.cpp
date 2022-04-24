class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>c_in;
    unordered_map<string,vector<int>>ans;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName,int t) {
        pair<string,int>p= make_pair(stationName,t);
        c_in[id] = p;
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p = c_in[id];
        string key =  p.first + "_"  + stationName;
        
        ans[key].push_back(t-p.second);        
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sum =0.0;
        string key = startStation + "_" + endStation;
        auto v = ans[key];
        
        for(int i : v)
            sum+=i+0.0;
        
       return sum/v.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */