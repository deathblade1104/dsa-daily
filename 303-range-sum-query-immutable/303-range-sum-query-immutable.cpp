class NumArray {
public:
    int ps[10001];
    NumArray(vector<int>& nums) {
        memset(ps,0,sizeof(ps));
        
        ps[0]=nums[0];
        
        for(int i=1;i<nums.size();i++)
            ps[i]= nums[i] + ps[i-1];
    }
    
    int sumRange(int left, int right) {

        if(left==0)
            return ps[right];
        
        return ps[right] - ps[left-1];
        

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */