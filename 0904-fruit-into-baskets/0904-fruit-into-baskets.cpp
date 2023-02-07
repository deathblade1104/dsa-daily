class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int start = 0,ans = 0;
        for(int i=0;i<fruits.size();i++){
            
            mp[fruits[i]]++;
            
            while(mp.size()>2){
                
                if(mp[fruits[start]] ==1)
                    mp.erase(fruits[start]);
                
                else mp[fruits[start]]--;
                
                start++;
            }
            
            ans = max(ans,i - start + 1);
        }
        
        return ans;
    }
};