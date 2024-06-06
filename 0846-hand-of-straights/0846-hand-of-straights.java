class Solution {
    public boolean isNStraightHand(int[] nums, int k) {
        
        int n = nums.length;
        
        if(n%k != 0)
            return false;
        
        Map<Integer,Integer> mp = new TreeMap();
        
        for(int i : nums){
            mp.put(i,mp.getOrDefault(i,0)+1);
        }
        
        while(mp.size() >0){
            
            int last = -1,count = 0;
            
            
            for(int key : mp.keySet()){
                if(last == -1){
                    last = key;
                    break;
                }
            }
            
            while(count<k){
                
                int currFreq = mp.getOrDefault(last,0);
             
                if(currFreq <=0)
                    return false;
                
                if(--currFreq <=0)
                    mp.remove(last);               
                
                else mp.put(last,currFreq);
                
                last++;
                count++;    
            }    
        }
        
        return true;
        
    }
}