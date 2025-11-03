class Solution {
public:
    
    bool isPossible(vector<int>&arr,int cars,long long&mid){
        
        long long curr = 0;
        for(int&i : arr){
            curr+=(long long)sqrt(mid / i);
            
            if(1LL *cars<=curr)
                return true;
        }
        
        return false;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high = LLONG_MAX,ans = -1;

        sort(ranks.begin(),ranks.end());
        
        while(low<=high){
            long long mid = low + ((high - low)/2);
            
            if(isPossible(ranks,cars,mid)){
                ans = mid;
                high = mid - 1;
            }
            
            else low = mid + 1;
        }
        
        return ans;
    }
};