class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        vector<int>ans;
        
        if(changed.size()%2==1)
            return ans;
        
        unordered_map<int,int>mp;
        
        for(int&i : changed)
            mp[i]++;
        
        
        int req = changed.size()/2;
        sort(changed.begin(),changed.end());
        
        for(int i=0;i<changed.size() and req>0;i++){
           
            int curr = changed[i] * 2;
            
            if(mp.count(changed[i])==1 and mp.count(curr)==1)
            {
                if(curr==0 and mp[curr]==1)
                    continue;
                
                if(mp[curr]==1)
                    mp.erase(curr);
                
                else mp[curr]--;
                
                if(mp[changed[i]]==1)
                    mp.erase(changed[i]);
                
                else mp[changed[i]]--;
                
                ans.push_back(changed[i]);
                req--;
            }
        }
        
     if(req ==0)
         return ans;
        
    return {};
        
    }
};