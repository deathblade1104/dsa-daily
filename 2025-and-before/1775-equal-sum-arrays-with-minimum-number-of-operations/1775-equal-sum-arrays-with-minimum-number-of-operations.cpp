class Solution {
public:
    static array<int,6>arr;
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        int sum1  = accumulate(nums1.begin(),nums1.end(),0);
        int sum2  = accumulate(nums2.begin(),nums2.end(),0);
        
        if(sum1<sum2){
            swap(nums1,nums2);
            swap(sum1,sum2);
        }

        
        int diff = sum1 - sum2;
        
        if(diff == 0)
            return 0;
        
        arr.fill(0);
        
        for(int&i : nums1){
           arr[i-1]++;   
        }
        
        for(int&i : nums2){
            arr[6-i]++;
        }
        
        int ans = 0;

        for(int i=5;i>=1;i--){
            
            
            int op = min(arr[i],(int)ceil(1.0 * diff/i));
           
            ans+=op;
            
            
            diff-=(op * i);
           
            
            if(diff<=0)
                return ans;
        }
        return -1;
        
    }
};

array<int,6>Solution::arr;