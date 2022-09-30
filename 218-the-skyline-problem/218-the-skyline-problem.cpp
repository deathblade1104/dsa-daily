class Solution {
public:
    
    struct mycomp{
        
        bool operator()(const vector<int>&a, const vector<int>&b){
            
            if(a[0]==b[0])
                return a[1]<=b[1];
            
            return a[0]<b[0];
        }
    };
    
    vector<vector<int>>transformationHelper(vector<vector<int>>&buildings){
        
        vector<vector<int>>ans;
        
        for(auto&v : buildings){
            ans.push_back({v[0],-v[2]});
            ans.push_back({v[1],v[2]});
        }
        
        sort(ans.begin(),ans.end(),mycomp());
        return ans;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<vector<int>>temp = transformationHelper(buildings);
        vector<vector<int>>ans;
        map<int,int>mp;
        mp[0]++;
        
        int prevMax = 0,itr=0;
        
        for(auto&v : temp){
            
            if(v[1]<0)
                mp[-v[1]]++;
            else{
                
                if(mp[v[1]]==1)
                    mp.erase(v[1]);
                
                else mp[v[1]]--;
            }
            
            int currMax =mp.rbegin()->first;
            
            if(prevMax!=currMax){
                ans.push_back({v[0],currMax});
                prevMax = currMax;
            }
        }
        
        return ans;
        
        
    }
};