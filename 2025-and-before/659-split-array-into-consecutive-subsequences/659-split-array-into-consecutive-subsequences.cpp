class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int cnt[2001] ={0};
        
        for(int&i: nums)
            cnt[i+1000]++;
        
        
        for(int i=0;i<=1998;i++){
            
           while (cnt[i]) {
                int c = 1;
                while (cnt[i+c-1] <= cnt[i+c]) {
                    cnt[i+c-1]--;
                    c++;
                }
            
                cnt[i+c-1]--;
                // c++;
               
                if (c < 3) return false;
            }
        }
        if(cnt[1999] or cnt[2000])
            return false;
        
        return true;
        
        
    }
};