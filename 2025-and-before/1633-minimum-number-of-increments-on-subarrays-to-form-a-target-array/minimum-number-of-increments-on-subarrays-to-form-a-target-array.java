class Solution {
    public int minNumberOperations(int[] target) {
        int ans = target[0];
        for(int i=1;i<target.length;i++){
            int diff = target[i] - target[i-1];
            if(diff<=0)
                continue;
            ans+=diff;
        }

        return ans;
    }
}