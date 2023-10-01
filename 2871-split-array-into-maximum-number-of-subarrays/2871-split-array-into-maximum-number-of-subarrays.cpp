class Solution {
public:
    int maxSubarrays(vector<int>& A) {
        
        int v = -1, res = 0;
        
        for (int&a: A)
            if ((v &= a) == 0)
                v--, res++;
        
        return max(1, res);
        
    }
};