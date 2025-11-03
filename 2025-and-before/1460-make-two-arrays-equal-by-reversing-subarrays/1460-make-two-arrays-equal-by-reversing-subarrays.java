class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        HashMap<Integer,Integer>mp  = new HashMap<>();
        for(int i : arr )
            mp.put(i,mp.getOrDefault(i,0)+1);
        
        for(int i : target){
            int curr = mp.getOrDefault(i,0);
            if(curr == 0)
                return false;
             mp.put(i,curr-1);
        }
        
        return true;
    }
}