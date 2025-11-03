class Solution {
public:
    static int hashMap[101];
    
    int maxFrequencyElements(vector<int>& nums) {
        memset(hashMap,0,sizeof hashMap);
        int maxi = 0;
        
        for(int&i : nums){
            hashMap[i]++;
            maxi = max(maxi,hashMap[i]);
        }
        

        int ans = 0;        
        for(int i=0;i<=100;i++){
            if (hashMap[i] == maxi)
                ans+=hashMap[i];
            
        }
        
        return ans;
        
    }
};

int Solution :: hashMap[101];