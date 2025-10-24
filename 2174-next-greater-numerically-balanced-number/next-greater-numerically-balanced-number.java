class Solution {
    private static boolean isInstantiated = false;
    private static List<Long> list;

    public Solution() {
        if (isInstantiated) 
            return;

        isInstantiated = true;
        list = new ArrayList<>();
        generate(0, new int[10]);
        Collections.sort(list);
    }

    private static void generate(long num, int[] count) {
        if (num > 0 && isBeautiful(count))
            list.add(num);
            
        if (num > 1224444L) return;

        for (int d = 1; d <= 7; d++) {
            if (count[d] < d) {
                count[d]++;
                generate(num * 10 + d, count);
                count[d]--;
            }
        }
    }

    private static boolean isBeautiful(int[] count) {
        for (int d = 1; d <= 7; d++) {
            if (count[d] != 0 && count[d] != d) return false;
        }
        return true;
    }

    public int nextBeautifulNumber(int n) {
        int low = 0, high = list.size() - 1, ans = -1;

        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (list.get(mid) > n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans == -1 ? -1 : list.get(ans).intValue();
    }
}
