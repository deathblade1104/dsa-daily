class Solution {
public:
    bool isPossible(vector<int>&weights,long long int&mid,int&days){
        
        long long int countDays = 1,currCap = 0;
        
        for(int&i : weights){
            
            if(currCap+i > mid){
                countDays++;
                currCap=0;
            }
            
            
            currCap+=i;
            
            if(countDays>1LL * days)
                return false;
            
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int&days) {
        
        long long int low = 0LL,high = 0LL,ans = -1 ;
        
        for(int&i : weights){
            high+=(1LL *i);
            low = max(low,1LL * i);
        }
        
        high*=1LL * days;
        
        
        while(low<=high){
            
            long long int mid = low + ((high - low)/2);
            //cout<<mid<<" --> ";
            if(isPossible(weights,mid,days)){
                ans = mid;
                high = mid - 1;
                
                //cout<<true<<endl;
            }
            
            else{
                
            low = mid + 1;
                //cout<<false<<endl;
            }
        }
        
        return ans;
        
    }
};