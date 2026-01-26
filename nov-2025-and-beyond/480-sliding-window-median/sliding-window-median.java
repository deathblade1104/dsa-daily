class Solution {

    // 0 = first (smallest k/2,k/2 +1), 1 (largest k/2)
    TreeMap<Integer,Integer>[] maps;
    int[] allowedSizes;   // [k/2 or k/2 +1, k/2]
    int[] sizes;          // current sizes
    boolean isOdd;

    //Median Helper
    private double getMedian(){
        if(isOdd){
            return maps[0].lastKey() *1.0;
        }
        return (0.0 + maps[0].lastKey() + maps[1].firstKey())/2.0;
    }

    // ---------- multiset helpers ----------
    private void add(int idx, int x) {
        TreeMap<Integer,Integer> mp = maps[idx];
        mp.put(x, mp.getOrDefault(x, 0) + 1);
        sizes[idx]++;
    }

    private void remove(int idx, int x) {
        TreeMap<Integer,Integer> mp = maps[idx];
        int cnt = mp.get(x);
        if (cnt == 1) mp.remove(x);
        else mp.put(x, cnt - 1);
        sizes[idx]--;
    }

    // ---------- rebalance by size as well as by order ----------
    private void rebalance() {
       // Fix size first
        while (sizes[0] > allowedSizes[0]) {
            int x = maps[0].lastKey();
            remove(0, x);
            add(1, x);
        }
        while (sizes[0] < allowedSizes[0] && sizes[1] > 0) {
            int x = maps[1].firstKey();
            remove(1, x);
            add(0, x);
        }

        // Fix ordering if violated
        // Three partition has stronger boundaries. 
        // but in 2 part boundaries are weaker. 
        while (sizes[0] > 0 && sizes[1] > 0 && maps[0].lastKey() > maps[1].firstKey()) {
            int a = maps[0].lastKey();
            int b = maps[1].firstKey();
            remove(0, a);
            remove(1, b);
            add(0, b);
            add(1, a);
        }
    }

    // ---------- delete from the window ----------
    private void deleteElement(int x) {
        for (int i = 0; i < 2; i++) {
            if (maps[i].containsKey(x)) {
                remove(i, x);
                return;
            }
        }
    }

    private void addElement(int ele){
        // if ele is smaller than largets ele in first window insert here
        if(sizes[0] == 0|| ele <= maps[0].lastKey()){
            add(0,ele);
            return;
        }
        add(1,ele);
        
    }


    public double[] medianSlidingWindow(int[] nums, int k) {

        isOdd = k%2== 1;
        int mid = k/2;
        if(isOdd){
            allowedSizes = new int[]{mid+1,mid};
        }
        else allowedSizes = new int[]{mid, mid};
        sizes = new int[]{0, 0};
        maps = new TreeMap[2];
        for (int i = 0; i < 2; i++) {
            maps[i] = new TreeMap<>();
        }

        List<Double>ans = new ArrayList<>();

        for(int i=0;i<k;i++){
            addElement(nums[i]);   
        }

        rebalance();
        int n = nums.length;
        double[] res = new double[n-k+1];
        res[0] = getMedian();

        for(int i=k;i<n;i++){
            deleteElement(nums[i-k]);
            addElement(nums[i]);
            rebalance();
            res[i-k+1] = getMedian();
        }

        return res;
        
    }
}