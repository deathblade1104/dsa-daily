class Solution {

    private int getContributionOfEachCharacter(List<Integer>list, int n){

        int sz = list.size();
        //This character was never present in the string
        if(sz == 2 && list.get(0) == -1 && list.get(1) == n)
            return 0;

        int res = 0;
        //Actual occurences 0 to n-1 of string
        for(int i=1;i<sz-1;i++){
            int prev = list.get(i - 1);
            int curr = list.get(i);
            int next = list.get(i + 1);

            res += (curr - prev) * (next - curr);
        }

        return res;
    }

    public int uniqueLetterString(String s) {

       List<Integer>[] arr = new ArrayList[26];
       for(int i=0;i<26;i++){
            arr[i] = new ArrayList<>();
            arr[i].add(-1);
       }

       int n = s.length();
       for(int i=0;i<n;i++){
            char ch = s.charAt(i);
            int idx = ch - 'A';
            arr[idx].add(i);
       }

       long ans = 0L;
       for(int i=0;i<26;i++){
            List<Integer>list = arr[i];
            list.add(n);
            ans+=0L + getContributionOfEachCharacter(list,n);
       }       

       return (int) ans;

    }
}