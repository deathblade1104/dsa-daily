class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        
        int i=0,n=costs.size();
        while(i<n and costs[i]<=coins){
            coins-=costs[i++];
        }
        
        return i;
        
    }
};