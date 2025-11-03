class RangeFreqQuery {
public:
    
    vector<unordered_map<int,int>>v;
    int n;
    RangeFreqQuery(vector<int>& arr) {
        
        n = arr.size();
        v.resize(4*n);
        
        buildSegTree(0,n-1,0,arr);
    }
    
    void buildSegTree(int start,int end,int currIdx, vector<int>&arr){
        
        if(start>end)
            return;
        
        if(start == end){
            v[currIdx][arr[start]]=1;
            return;
        }
        
        int mid = start + ((end - start)/2);
        
        buildSegTree(start,mid,currIdx*2+1,arr);
        buildSegTree(mid+1,end,currIdx*2 +2,arr);
        
        v[currIdx] = mergeMaps(v[currIdx*2 + 1], v[currIdx*2 + 2]);
    }
    
    unordered_map<int,int>mergeMaps(unordered_map<int,int>&mp1,unordered_map<int,int>&mp2){
        
        unordered_map<int,int>ans = mp1;
        
        for(auto&it : mp2){
            if(ans.count(it.first)==1)
            ans[it.first]+=it.second;
            
            else
            ans[it.first] = it.second;
        }
        
        return ans;
    }
    
    
    int query(int left, int right, int value) {
        
        return querySolver(0,n-1,0,left,right,value);
    }
    
    int querySolver(int start,int end,int currIdx, int&left,int&right,int&val){
        
        if(start>end or start>right or end<left)
            return 0;
        
        if(start>=left and end<=right){
            
            if(v[currIdx].count(val)==1)
                return v[currIdx][val];
            
            return 0;
        }
        
        int mid = start + ((end - start)/2);
        
        return querySolver(start,mid,currIdx*2+1,left,right,val) + 
               querySolver(mid+1,end,currIdx*2+2,left,right,val);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */