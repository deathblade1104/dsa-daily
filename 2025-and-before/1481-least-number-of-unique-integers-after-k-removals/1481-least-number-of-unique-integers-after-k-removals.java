class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
         Map<Integer, Integer> mp = new HashMap<>();
        for (int i : arr) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }
        
        // Step 2: Convert the HashMap entries to a List of arrays
        List<int[]> st = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            int[] arrEntry = {entry.getValue(), entry.getKey()};
            st.add(arrEntry);
        }
        
        // Step 3: Sort the List based on frequency (first element of array) in descending order
        Collections.sort(st, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return Integer.compare(b[0], a[0]);
            }
        });
        
        // Step 4: Process elements to find remaining size after removing k elements
        while (k > 0 && !st.isEmpty()) {
            int[] curr = st.get(st.size() - 1);
            if (k >= curr[0]) {
                k -= curr[0];
                st.remove(st.size() - 1);
            } else {
                break;
            }
        }
        
        // Step 5: Return remaining size
        return st.size();
    
        
    }
}