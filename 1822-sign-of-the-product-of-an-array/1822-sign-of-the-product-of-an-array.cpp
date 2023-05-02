class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0, zero = 0;
        
        for(int&i : nums){
            
            if(i ==0 )
                zero++;
            
            if(i<0)
                neg++;
        }
        
        
        if(zero>0)
            return 0;
        
        if(neg&1)
            return -1;
        
        return 1;
    }
};