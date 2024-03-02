class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        int sum1  = accumulate(nums1.begin(),nums1.end(),0);
        int sum2  = accumulate(nums2.begin(),nums2.end(),0);
        
        if(sum1>sum2){
            swap(nums1,nums2);
            swap(sum1,sum2);
        }
        
        if(sum2 == sum1)
            return 0;
        
        int diff = abs(sum2 - sum1);
        
        vector<int>arr;
        
        for(int&i : nums1){
            if(i == 6)
                continue;
            
            arr.push_back(6-i);
        }
        
        for(int&i : nums2){
            if(i == 1)
                continue;
            
            arr.push_back(i-1);
        }
        
        sort(arr.rbegin(), arr.rend());
		
        int ans = 0;
        
        for(int &x: arr){
            ans++; 
            diff -= x;
            if(diff <= 0) return ans;
        }
        return -1;
        
    }
};