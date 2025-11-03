class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        
    
        HashMap<Integer,Integer>mp = new HashMap<>();
        int ans = 0,sum = 0,n = nums.length; 
        for(int i=0;i<n;i++){
            sum = (sum%k + nums[i]%k + k)%k;
            
            if(sum == 0)
                ans++;
            
            int curr = mp.getOrDefault(sum,0);
            ans+=curr;
            
            mp.put(sum,curr+1);
        }
        
        return ans;
        
    }
}