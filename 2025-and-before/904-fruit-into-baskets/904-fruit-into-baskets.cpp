class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int start=0,ans=0;        
        
        for(int end=0;end<fruits.size();end++)
        {
            if(mp.count(fruits[end])==0 and mp.size()==2)
            {
                while(mp.size()>=2)
                {
                    if(mp[fruits[start]]>1)
                        mp[fruits[start]]--;
                    
                    else
                        mp.erase(fruits[start]);
                    
                    start++;
                }
            }
            
            mp[fruits[end]]++;
            ans = max(ans,(end - start +1));
        }
        
        return ans;
        
    }
};