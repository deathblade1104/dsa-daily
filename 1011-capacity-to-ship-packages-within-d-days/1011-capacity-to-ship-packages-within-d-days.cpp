class Solution {
public:
    
    bool isPossible(vector<int>&weights,int&mid,int&days){
        
        int currDays = 1, currCount = weights[0];
        
        for(int i=1;i<weights.size();i++){
            
            currCount+=weights[i];
            if(currCount>mid){
                currCount=weights[i];
                currDays++;
            }
            
            if(currDays>days)
                return false;
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        
        int low = 1, high = 1e9,ans=-1;
        
        for(int&i : weights){
            low = max(i,low);
        }
        
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(isPossible(weights,mid,days)){
                ans = mid;
                high = mid-1;
            }
            
            else 
                low = mid +1 ;
        }
        
        return ans;
    }
};