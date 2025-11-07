class Solution {

    private static class Pair {
        int freq, val;
        Pair(int f, int v) {
            freq = f;
            val = v;
        }
    }

    private static class PairCmp implements Comparator<Pair> {
        public int compare(Pair a, Pair b) {
            if (a.freq != b.freq)
                return Integer.compare(a.freq, b.freq);
            
            return Integer.compare(a.val, b.val);
        }
    }

    HashMap<Integer, Integer> freq;
    HashMap<Integer, Pair> mp;
    private static final PairCmp cmp = new PairCmp();
    TreeSet<Pair> top, rest;
    long sumTop;
    int x;

    private void rebalance() {
        while (top.size() > x) {
            Pair p = top.pollFirst();
            sumTop -= 1L * p.freq * p.val;
            rest.add(p);
        }
        
        while (top.size() < x && !rest.isEmpty()) {
            Pair p = rest.pollLast();
            top.add(p);
            sumTop += 1L * p.freq * p.val;
        }
        
    
        
        while (!rest.isEmpty() && !top.isEmpty()) {
            Pair minTop = top.first();
            Pair maxRest = rest.last();
            
            if (cmp.compare(minTop, maxRest)>=0) {
                break;
            } 

            top.pollFirst();
            sumTop -= 1L * minTop.freq * minTop.val;
            rest.pollLast();
    
            top.add(maxRest);
            sumTop += 1L * maxRest.freq * maxRest.val;
            rest.add(minTop);
        }
    }

    private void update(int val, int newFreq) {
        Pair old = mp.get(val);

        if (old != null) {
            if (top.remove(old)) {
                sumTop -= 1L * old.freq * old.val;
            } else {
                rest.remove(old);
            }
        }

        if (newFreq > 0) {
            Pair np = new Pair(newFreq, val);
            mp.put(val, np);
            rest.add(np);
        } else {
            mp.remove(val);
        }

        rebalance();
    }

    public long[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        long[] ans = new long[n - k + 1];
        this.x = x;

        freq = new HashMap<>();
        mp = new HashMap<>();
        top = new TreeSet<>(new PairCmp());
        rest = new TreeSet<>(new PairCmp());
        sumTop = 0;

        for (int i = 0; i < k; i++)
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);

        for (var e : freq.entrySet()) {
            Pair p = new Pair(e.getValue(), e.getKey());
            mp.put(e.getKey(), p);
            rest.add(p);
        }

        rebalance();
        ans[0] = sumTop;

        for (int i = k; i < n; i++) {
            int out = nums[i - k];
            int oldFreq = freq.get(out);
            if (oldFreq == 1) {
                freq.remove(out);
                update(out, 0);
            } else {
                freq.put(out, oldFreq - 1);
                update(out, oldFreq - 1);
            }

            int in = nums[i];
            int newFreq = freq.getOrDefault(in, 0) + 1;
            freq.put(in, newFreq);
            update(in, newFreq);

            ans[i - k + 1] = sumTop;
        }

        return ans;
    }
}