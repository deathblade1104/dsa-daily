class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>c_in;
    unordered_map<string,pair<int,int>>ans;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName,int t) {
        pair<string,int>p= make_pair(stationName,t);
        c_in[id] = p;
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p = c_in[id];
        string key =  p.first + "_"  + stationName;
        
        ans[key].first+=(t-p.second);
        ans[key].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "_" + endStation;
        
        return (double)((ans[key].first*1.0)/ans[key].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */