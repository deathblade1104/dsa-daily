class SnapshotArray {
public:
    
    vector<int>v[50001];
    unordered_map<int,unordered_map<int,int>>mp;
    int len, snapId;
    SnapshotArray(int length) {
        
        len = length;
        snapId = 0;
    }
    
    void set(int index, int val) {
     mp[index][snapId] = val; 
        
        if(v[index].size() == 0 or v[index].back()<snapId)
            v[index].push_back(snapId);
        
    }
    
    int snap() {
        
        snapId++;
        return snapId - 1;
    }
    
    int get(int index, int snap_id) {
        
        if(index >=len)
            return 0;
        
        int low = 0, high = v[index].size() - 1,ans = -1;
        
        while(low<=high){
            
            int mid = low + ((high - low))/2;
            
            if(v[index][mid]<=snap_id){
                ans = mid;
                low = mid + 1;
            }
            
            else high = mid - 1;
        }
        
        
        if(ans == -1)
            return 0;
        
        return mp[index][v[index][ans]];
        
        
        
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */