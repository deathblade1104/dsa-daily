class Solution {
public:
    
    bool isPossible(vector<int>&dist,double&hour, int mid){
        
        double temp = 0.0;
        
        for(int i=0;i<dist.size()-1;i++){
            
            if(dist[i]%mid ==0)
                temp+=(dist[i]*1.0)/(mid*1.0);
            
            else
            {
                int div = (int)(floor(dist[i]/mid));
                div++;
                
                temp+=(div * 1.0);
            }
        }
        
        temp+=(dist.back()*1.0)/(mid*1.0);
    
        return temp<=hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
            
        int low=1,high=1e9,ans=-1;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(isPossible(dist,hour,mid)){
                ans = mid;
                high = mid -1;
            }
            
            else
                low = mid + 1;
        }
        
        return ans;
    }
};