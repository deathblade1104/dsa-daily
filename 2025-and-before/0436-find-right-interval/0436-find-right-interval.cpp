class Solution {
public:
    
    int search(vector<array<int,2>>&v,int val,int&n){
        
        if(val>v.back()[0])
            return -1;
        
        
        int low=0,high = n-1,ans =-1;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(v[mid][0]>=val){
                high = mid -1;
                ans = mid;
            }
            else 
                low = mid + 1;
        }
        
        return v[ans][1];   
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int n= intervals.size();
        vector<array<int,2>>v;
        for(int i=0;i<n;i++){
            v.push_back({intervals[i][0],i});
        }
        
        sort(v.begin(),v.end());
        
        vector<int>ans(n,-1);
        
        for(int i=0;i<n;i++){
            
            ans[i] = search(v,intervals[i][1],n);
        }
        
        
        return ans;
    }
};