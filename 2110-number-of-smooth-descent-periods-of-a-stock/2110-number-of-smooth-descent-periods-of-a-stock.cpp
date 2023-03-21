class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        
        long long ans = 0,currCount = 0;
        
        for(int i = 1;i<prices.size();i++){
            
            
            if(prices[i-1] - prices[i] == 1){
                currCount++;
                ans+=currCount;
            }
            
            else
                currCount = 0;
        }
        
        
        ans+=prices.size();
        
        return ans;
    }
};