class Solution {
public:
    bool isPossible(vector<int>&bloomDays,int&n,int&m,int&k,int&mid){
        
        int count = 0,start=0;
        
        for(int i=0;i<n;i++){
            if(bloomDays[i]>mid)
                start = i+1;
            
            if(i - start + 1 == k){
                count++;
                start = i+1;
            }
        }
        
        
        return (count>=m) ? true : false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        
        long long total = 1LL * m * k;
        
        if(total > (n *1LL))
            return -1;
        
        int low = INT_MAX, high = 0,ans=-1;
        
        for(int&i : bloomDay){
            
            low =min(low,i);
            high = max(high,i);
        }
        

        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(isPossible(bloomDay,n,m,k,mid)){
                ans = mid;
                high = mid - 1;
            }
            
            else
                low = mid + 1;
        }
        
        return ans;
        
    }
};