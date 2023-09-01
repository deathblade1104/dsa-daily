class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result(n+1,0);

        int offset = 1;

        for (int index = 1; index < n + 1; ++index){
            if (offset * 2 == index){
                offset *= 2;
            }
            result[index] = result[index - offset] + 1;
        }
        return result;
        
    }
};