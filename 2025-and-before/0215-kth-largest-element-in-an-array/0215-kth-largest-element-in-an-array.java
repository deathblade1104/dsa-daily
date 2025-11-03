class Solution {
    public int findKthLargest(int[] nums, int k) {

        
        PriorityQueue<Integer>pq = new PriorityQueue<Integer>(k+1,Comparator.reverseOrder());
        
        int n = nums.length;
        k = n -k+1;
        
        for(int i=0;i<n;i++){
            pq.add(nums[i]);
            
            if(pq.size() >k)
                pq.poll();
        }
        
        return pq.poll();
        
    }
}