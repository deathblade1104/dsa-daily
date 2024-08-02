class Solution {
    public int minSwaps(int[] nums) {
        
        int oneCount = 0,n = nums.length;
        ArrayList<Integer>modifiedNums = new ArrayList<>(n + n);
        
        for(int i : nums){
            if(i == 1)
                oneCount++;
            modifiedNums.add(i);
        }
        
        if(oneCount == n)
            return 0;
        
        for(int i : nums){
            modifiedNums.add(i);
        }
        
        int maxNums = 0,currCount = 0;
        
        for(int i=0;i<oneCount;i++){
            if(modifiedNums.get(i) == 1)
                currCount++;
        }
        
        maxNums = currCount;
        
        for(int i=oneCount;i<(n+n);i++){
            
            if(modifiedNums.get(i) == 1)
                currCount++;
            
            if(modifiedNums.get(i - oneCount) == 1)
                currCount--;
            
            maxNums = Math.max(maxNums,currCount);
        }
        
        return oneCount - maxNums;
    }
}