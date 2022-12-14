class Solution {
public:
    
    bool checker(int&l,int&r, vector<int>&nums){
        
        vector<int>temp(r-l+1);
        
        for(int i=l;i<=r;i++)
            temp[i-l] = nums[i];
        
        sort(temp.begin(),temp.end());
        
        int prev = temp[1] - temp[0];
        
        for(int i=2;i<temp.size();i++){
            
            int curr = temp[i] - temp[i-1] ;
            
            if(curr != prev)
                return false;
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n = nums.size(), m = l.size();
        vector<bool>ans(m);
        
        
        for(int i =0;i<m;i++){
            int l1 = l[i],r1=r[i];
            
            if(r1 - l1 <=1)
                ans[i] = true;
            
            else ans[i] = checker(l1,r1,nums);
        }
        
        return ans;
    }
};