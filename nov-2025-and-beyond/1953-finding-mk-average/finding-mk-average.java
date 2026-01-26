class MKAverage {

    int m, k;
    Deque<Integer> deque;

    // 0 = first (smallest k), 1 = mid, 2 = last (largest k)
    TreeMap<Integer,Integer>[] maps;
    int[] allowedSizes;   // [k, m-2k, k]
    int[] sizes;          // current sizes
    long midSum;

    public MKAverage(int m, int k) {
        this.m = m;
        this.k = k;

        deque = new ArrayDeque<>();

        allowedSizes = new int[]{k, m - 2*k, k};
        sizes = new int[]{0, 0, 0};

        maps = new TreeMap[3];
        for (int i = 0; i < 3; i++) {
            maps[i] = new TreeMap<>();
        }

        midSum = 0L;
    }

    // ---------- multiset helpers ----------

    private void add(int idx, int x) {
        TreeMap<Integer,Integer> mp = maps[idx];
        mp.put(x, mp.getOrDefault(x, 0) + 1);
        sizes[idx]++;
        if (idx == 1) midSum += x;
    }

    private void remove(int idx, int x) {
        TreeMap<Integer,Integer> mp = maps[idx];
        int cnt = mp.get(x);
        if (cnt == 1) mp.remove(x);
        else mp.put(x, cnt - 1);

        sizes[idx]--;
        if (idx == 1) midSum -= x;
    }

    // ---------- boundary moves ---------
    private void moveFirstToMid() {
        int x = maps[0].lastKey();
        remove(0, x);
        add(1, x);
    }

    private void moveMidToFirst() {
        int x = maps[1].firstKey();
        remove(1, x);
        add(0, x);
    }

    private void moveMidToLast() {
        int x = maps[1].lastKey();
        remove(1, x);
        add(2, x);
    }

    private void moveLastToMid() {
        int x = maps[2].firstKey();
        remove(2, x);
        add(1, x);
    }

    // ---------- rebalance by size only ----------
    private void rebalance() {

        // Fix first (smallest k)
        while (sizes[0] > allowedSizes[0]) {
            moveFirstToMid();
        }
        while (sizes[0] < allowedSizes[0] && sizes[1] > 0) {
            moveMidToFirst();
        }

        // Fix last (largest k)
        while (sizes[2] > allowedSizes[2]) {
            moveLastToMid();
        }
        while (sizes[2] < allowedSizes[2] && sizes[1] > 0) {
            moveMidToLast();
        }
    }

    // ---------- delete oldest ----------
    private void deleteElement(int x) {
        for (int i = 0; i < 3; i++) {
            if (maps[i].containsKey(x)) {
                remove(i, x);
                return;
            }
        }
    }

    // ---------- main ops ----------
    public void addElement(int num) {

        // Remove oldest if window full
        if (deque.size() >= m) {
            int old = deque.pollFirst();
            deleteElement(old);
            rebalance();
        }

        deque.offerLast(num);

        // Insert into correct partition
        if (sizes[0] > 0 && num <= maps[0].lastKey()) {
            add(0, num);
        }
        else if (sizes[2] > 0 && num >= maps[2].firstKey()) {
            add(2, num);
        }
        else {
            add(1, num);
        }

        rebalance();
    }

    public int calculateMKAverage() {

        if (deque.size() < m) return -1;

        return (int)(midSum / (m - 2 * k));
    }
}
