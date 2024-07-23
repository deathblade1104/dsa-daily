class Solution {
    public int[] frequencySort(int[] nums) {
        
        int n = nums.length;
        HashMap<Integer,Integer>mp = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }
        
         
        ArrayList<Integer> numList = new ArrayList<>();
        for (int num : nums) {
            numList.add(num);
        }

        // Sort the list based on the frequency
        Collections.sort(numList, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                int freqA = mp.get(a);
                int freqB = mp.get(b);
                if (freqA != freqB) {
                    return freqA - freqB; 
                } else {
                    return b - a;
                }
            }
        });

        // Convert the sorted list back to an array
        for (int i = 0; i < n; i++) {
            nums[i] = numList.get(i);
        }

        return nums;
        
        
    }
}