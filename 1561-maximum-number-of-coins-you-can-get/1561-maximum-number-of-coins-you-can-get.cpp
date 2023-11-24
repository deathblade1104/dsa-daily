class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin(),piles.end());
        
        int n = piles.size(),i=0,j=n-2,ans =0;
        
        while(i<j){
            ans+=piles[j];
            j-=2;
            i++;
        }
        
        return ans;
        
    }
};