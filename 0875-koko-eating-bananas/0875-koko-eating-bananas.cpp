class Solution {
public:
    bool isPossible(int&mid, vector<int>&piles,int&h)
    {
         long long req_hours=0;
        
        for(int &j: piles)
        {        
            int curr=0,i = j;
            
            if(i<=mid)
                curr++;
            
            else 
            {
                if(i%mid==0)
                    curr=(i/mid);
                
                else
                    curr= (i/mid) +1;
            }
            
            req_hours +=curr;
        }
        
        return (req_hours<=h); 
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
       int high = 0 ,ans=0,low = 1; 
        
        for(int&i : piles)
         high = max(high,i);
                        
        while(low<=high)
        {
            int mid = low + ((high - low)/2);
            
            if(isPossible(mid,piles,h))
            {
                ans=mid;
                high= mid - 1; 
            }
            
            else 
                low = mid + 1;
        }
        
        return ans;
        
    }
};