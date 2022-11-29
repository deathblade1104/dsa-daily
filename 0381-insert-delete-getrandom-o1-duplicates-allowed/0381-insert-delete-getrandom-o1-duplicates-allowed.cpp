class RandomizedCollection {
public:
    unordered_map<int,unordered_set<int>>mp;
    vector<int>nums;
    
    RandomizedCollection() {
        nums.clear();
        mp.clear();
    }
    
    bool insert(int val) {
        
        bool ans = mp.count(val);
        
        nums.push_back(val);
        mp[val].insert(nums.size()-1);
        
        return !ans;
    }
    
    bool remove(int val) {
        
        if(mp.count(val)==0)
            return false;
        
        if(nums.back() == val){
            mp[val].erase(nums.size() - 1);
            
        }
        else{
            int idx = *(mp[val].begin());
            nums[idx] = nums.back();
            mp[val].erase(idx);
            mp[nums.back()].insert(idx);
            mp[nums.back()].erase(nums.size() - 1);
        }

        nums.pop_back();
        
        
        if(mp[val].size() == 0 )
            mp.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */