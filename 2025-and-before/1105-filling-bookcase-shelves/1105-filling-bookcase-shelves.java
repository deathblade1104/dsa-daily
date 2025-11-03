class Solution {
    
    private int n,maxWidth;
    private int[] dp;
    
    
    private int helper(int currIdx,int[][] books){
        
        if(currIdx>=n)
            return 0;
        
        if(dp[currIdx]!=-1)
            return dp[currIdx];
        
        int maxH = 0,nextMH = Integer.MAX_VALUE,currWidth = 0;
        
        for(int i=currIdx;i<n;i++){
            
            currWidth+=books[i][0];
            
            if(currWidth>maxWidth)
                break;
            
            maxH = Math.max(maxH,books[i][1]);
            nextMH = Math.min(nextMH,helper(i+1,books)+maxH);
            
        }
        
        return dp[currIdx] = nextMH;
    }
    
    public int minHeightShelves(int[][] books, int shelfWidth) {
        n = books.length;
        dp = new int[n+1];
        Arrays.fill(dp,-1);
        maxWidth = shelfWidth;
        
        return helper(0,books);
            
    }
}