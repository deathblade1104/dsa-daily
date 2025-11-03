// class TrieNode{
    
//     public char[] children;
//     public isEnd;
    
//     public 
// }

class Solution {
    public String kthDistinct(String[] arr, int k) {
        HashMap<String,Integer>mp= new HashMap<>();
        
        for(String s : arr){
            mp.put(s,mp.getOrDefault(s,0)+1);    
        }
        
        
        int count = 0;
        for(String s : arr){
            
            if(mp.get(s) == 1)
                count++;
            
            if(count == k)
                return s;
        }
        
        return "";
    }
}