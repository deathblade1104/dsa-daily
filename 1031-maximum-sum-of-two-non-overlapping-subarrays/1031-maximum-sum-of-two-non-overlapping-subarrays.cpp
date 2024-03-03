class Solution {
private : 
    int pref[1001],n;
public:
    
    int getSubArrSum(int l, int r){
        
        if(l<0 or r>=n)
            return 0;
        
        int currSum = pref[r];
        
        if(l)
            currSum -= pref[l-1];
        
        return currSum;
    }
    
    
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s){
        memset(pref,0,sizeof pref);
        n = nums.size();
        
        for(int i=0;i<n;i++){
            
            pref[i]+=nums[i];
            
            if(i)
                pref[i]+=pref[i-1];
        }
        
        
        if(f>s)
            swap(f,s);
        
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int secondSum = getSubArrSum(i,i+s-1);
            int firstSum;
            
            for(int j=i+s;j<n;j++){
                firstSum = getSubArrSum(j,j+f-1);
                ans = max(ans, secondSum + firstSum);
            }
            
            for(int j=0;j+f-1<i and j<n;j++){
                firstSum = getSubArrSum(j,j+f-1);
                ans = max(ans, secondSum + firstSum);
            }
        }
        
        return ans;
    }
};