class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(),pos=0,neg = 1;
        vector<int>ans(n);
        
        for(int&i : nums){
            
            if(i<0){
                ans[neg] = i;
                neg+=2;
            }
            
            else{
                ans[pos] = i;
                pos+=2;
            }
        }
        
        return ans;
        
    }
};