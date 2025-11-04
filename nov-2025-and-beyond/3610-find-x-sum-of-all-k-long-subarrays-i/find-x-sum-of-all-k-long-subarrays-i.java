class Solution {

    private int getTopX(TreeMap<Integer, TreeSet<Integer>> mp, int x) {
        int sum = 0;
        Map.Entry<Integer, TreeSet<Integer>> entry = mp.lastEntry();

        while (entry != null && x > 0) {
            int freq = entry.getKey();
            TreeSet<Integer> set = entry.getValue();

            Iterator<Integer> desc = set.descendingIterator();
            while (desc.hasNext() && x > 0) {
                int val = desc.next();
                sum += val * freq;
                x--;
            }

            entry = mp.lowerEntry(freq);
        }

        return sum;
    }

    private void removeFromMap(TreeMap<Integer, TreeSet<Integer>> mp, int freq, int val) {
        if (!mp.containsKey(freq)) return;
        TreeSet<Integer> set = mp.get(freq);
        set.remove(val);
        if (set.isEmpty()) mp.remove(freq);
    }

    private void addToMap(TreeMap<Integer, TreeSet<Integer>> mp, int freq, int val) {
        mp.putIfAbsent(freq, new TreeSet<>());
        mp.get(freq).add(val);
    }

    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];

        HashMap<Integer, Integer> freq = new HashMap<>();
        TreeMap<Integer, TreeSet<Integer>> mp = new TreeMap<>();

        
        for (int i = 0; i < k; i++) {
            int val = nums[i];
            int prevFreq = freq.getOrDefault(val, 0);

            if (prevFreq > 0)
                removeFromMap(mp, prevFreq, val);

            freq.put(val, prevFreq + 1);
            addToMap(mp, prevFreq + 1, val);
        }

        ans[0] = getTopX(mp, x);
        for (int i = k; i < n; i++) {
            int removeVal = nums[i - k];
            int addVal = nums[i];
            int prevFreq = freq.get(removeVal);
            removeFromMap(mp, prevFreq, removeVal);
            if (prevFreq == 1) freq.remove(removeVal);
            else {
                freq.put(removeVal, prevFreq - 1);
                addToMap(mp, prevFreq - 1, removeVal);
            }


            prevFreq = freq.getOrDefault(addVal, 0);
            if (prevFreq > 0) removeFromMap(mp, prevFreq, addVal);
            freq.put(addVal, prevFreq + 1);
            addToMap(mp, prevFreq + 1, addVal);
            ans[i - k + 1] = getTopX(mp, x);
        }
        return ans;
    }
}
