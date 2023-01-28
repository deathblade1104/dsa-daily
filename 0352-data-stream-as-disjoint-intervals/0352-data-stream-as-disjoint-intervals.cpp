class SummaryRanges {
public:
    vector<vector<int>>ans;
    unordered_set<int>st;
    
    SummaryRanges() {
        
        st.clear();
        ans.clear();
        
    }
    
    int search(vector<vector<int>>&ans,int val){
        
        int low = 0, high = ans.size()-1;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(ans[mid][1]<val)
                low = mid + 1;
            
            else if(ans[mid][0]>val)
                high = mid -1;
            
            else return mid;
        }
        
        return -1;
    }
    
    vector<vector<int>>remove(vector<vector<int>>&ans,int&prev,int&next){
        
        
        vector<vector<int>>res;
        
        for(int i=0;i<ans.size();i++){
            
            if(i!=prev and i!=next)
                res.push_back(ans[i]);
        }
        
        return res;
    }
    
    void addNum(int value) {
        
        if(st.count(value))
            return;
        
        //cout<<"Value is : "<<value<<endl;
    
        int prev = -1,next = -1;
        if(st.count(value - 1)){
            prev = search(ans,value-1);
            
            //cout<<"Index for prev : "<<prev<<endl;
            
            //cout<<"Prev is --> "<<ans[prev][0]<<" -- "<<ans[prev][1]<<endl;
        }
        
        if(st.count(value + 1)){
            next = search(ans,value+1);
            
            //cout<<"Index for next : "<<next<<endl;
            
            //cout<<"Next is --> "<<ans[next][0]<<" -- "<<ans[next][1]<<endl;
        }
        
        vector<int>toBeAdded(2);
        
        if(prev!=-1 and next==-1){
            toBeAdded[0]=ans[prev][0];
            toBeAdded[1]=value;
        }
        
        if(prev==-1 and next!=-1){
            toBeAdded[0]=value;
            toBeAdded[1]=ans[next][1];
            
        }
        
        if(prev!=-1 and next!=-1){
            toBeAdded[0]=ans[prev][0];
            toBeAdded[1]=ans[next][1];
        }
        
        if(prev==-1 and next ==-1){
            toBeAdded[0]=toBeAdded[1]=value;
        }
        
        ans = remove(ans,prev,next);
        ans.push_back(toBeAdded);
        sort(ans.begin(),ans.end());
        
        st.insert(value);
        
//         for(int i=0;i<ans.size();i++){
            
//             cout<<ans[i][0]<<" "<<ans[i][1]<<"  ,  ";
//         }
        
//         cout<<endl;
        return;
    }
    
    
    vector<vector<int>> getIntervals() {
        
        return ans;
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */