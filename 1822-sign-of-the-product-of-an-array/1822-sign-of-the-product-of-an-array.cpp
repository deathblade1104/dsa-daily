class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        
        for(int&i : nums){
            
            if(i ==0 )
                return 0;
            
            if(i<0)
                neg++;
        }
        
        if(neg&1)
            return -1;
        
        return 1;
    }
};