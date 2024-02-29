class Solution {
    public int minimumDeviation(int[] nums) {
        PriorityQueue<Integer> pq=new PriorityQueue<>(Collections.reverseOrder());
        int mini = Integer.MAX_VALUE,ans =Integer.MAX_VALUE;


        for(int i: nums){
            if(i%2 == 1)
                i*=2;
            
            mini = Math.min(mini,i);
            pq.offer(i);
        }
        
        
        while(!pq.isEmpty()){
            int curr = pq.poll();
            
            ans = Math.min(ans, curr - mini);
            
            if((curr&1) ==1)
                break;
            
            curr/=2;
            mini = Math.min(curr,mini);
            pq.offer(curr);
        }
        
        return ans;
        
    }
}