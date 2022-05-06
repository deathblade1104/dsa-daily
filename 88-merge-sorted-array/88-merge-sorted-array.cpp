class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums(m,-1);        
        for(int i=0;i<m;i++)
            nums[i]=nums1[i];
        
        int k=0,i=0,j=0;
        while(i<m and j<n)
        {
            if(nums[i]<=nums2[j])
                nums1[k++]=nums[i++];
            
            else
                nums1[k++]=nums2[j++];               
        }

        while(i<m)
        nums1[k++]=nums[i++]; 
        
        
        while(j<n)
        nums1[k++]=nums2[j++]; 
    }
};