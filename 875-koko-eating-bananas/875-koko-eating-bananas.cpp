class Solution {
public:
    bool isPossible(long long int mid, vector<int>&piles,long long int h)
    {
        long long int req_hours=0;
        
        for(int &j: piles)
        {        
           long long  int curr=0,i = j;
            
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
    
    int minEatingSpeed(vector<int>& piles, long long int h) {
        
       long long int sum =  0;
        
        for(int&i : piles)
         sum+=i;
                
       long long int ans=0,low = 1, high = sum;
        
        while(low<=high)
        {
            long long int mid = low + ((high - low)/2);
            
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