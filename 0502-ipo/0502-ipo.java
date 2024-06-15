class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;
        ArrayList<int[]> arr = new ArrayList<>();
        
        
        for(int i=0;i<n;i++){
            arr.add(new int[]{capital[i],profits[i]});
        }
        
        Collections.sort(arr, Comparator.comparingInt(a -> a[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        int i = 0;

        while (k-- > 0) {
        
            while (i < n && arr.get(i)[0] <= w) {
                pq.add(arr.get(i)[1]);
                i++;
            }
        
            if (pq.isEmpty()) {
                break;
            }

            w += pq.poll();
        }

        return w;
    }
}