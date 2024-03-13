class Solution {
public:
    int n,m;
    
    void removeFromMap(map<int,int>&mp,int&key){
        
         mp[key]--;
                
        if(mp[key] == 0)
            mp.erase(key);
        
        return;
    }
    
    bool isPossible(int midIndex,vector<int>&tasks, map<int,int>mp,int p,int&str){
    
        int i=midIndex;
        
        
        while(i>=0){
            
            auto it = mp.lower_bound(tasks[i]);
            int key;
            
            if(it == mp.end()){
                
                it = mp.lower_bound(tasks[i] - str);
        
                if(it == mp.end() || p<=0)
                    break;
                
                 p--;
            }
            
            key = it->first;
            removeFromMap(mp,key);
            i--;
        }
        
        return i<0;
    }
    
    
    int maxTaskAssign(vector<int>& tasks, vector<int>& work, int p, int str) {
        
        sort(tasks.begin(),tasks.end());
        map<int,int>mp;
        n = tasks.size();
        m = work.size();
        
        for(int&i : work)
            mp[i]++;
        
        int low = 0,high = min(n-1,m-1),ans = 0;
      
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(isPossible(mid,tasks,mp,p,str)){
                ans = mid+1;
                low = mid + 1;
            }
            
            else high = mid -1;
        }
        
        return ans;
    }
};