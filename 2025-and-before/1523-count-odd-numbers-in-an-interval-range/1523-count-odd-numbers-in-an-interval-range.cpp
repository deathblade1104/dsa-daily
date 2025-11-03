class Solution {
public:
    int countOdds(int low, int high) {
        int nums=high-low+1;
    
        int ans = nums/2;
        
		if(low&1  && high&1)
            ans++;
        
        return ans;
    }
};
