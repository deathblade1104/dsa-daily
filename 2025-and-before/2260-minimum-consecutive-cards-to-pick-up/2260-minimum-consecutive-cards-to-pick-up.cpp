class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_set<int>mp;
        mp.insert(cards[0]);
        
        int start=0,ans= cards.size()+5;
        
        for(int i=1;i<cards.size();i++)
        {
            while(mp.count(cards[i])==1 and start<i)
            {
                ans=min(ans,(i-start+1));               
                mp.erase(cards[start++]);
            }
            mp.insert(cards[i]);
        }
        
        if(ans==cards.size()+5)
            return -1;
               
        return ans;
        
    }
};