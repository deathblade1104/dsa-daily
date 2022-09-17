class Solution {
public:

    
    bool isPossible(vector<vector<int>>& transactions, long long m,long long&d){
        
        for(int i = 0; i<transactions.size(); i++)
        {
            if(transactions[i][0] >= transactions[i][1])
            {
                long long  d1 = transactions[i][0] - transactions[i][1];
                
                if(m - (d - d1) < transactions[i][0])
                    return false;
            }
             else if(m - d < transactions[i][0])
                    return false;
        }
        return true;
    }
    
    long long minimumMoney(vector<vector<int>>& transactions) {  
        long long low =0, high =0LL,ans=-1,d=0LL;
        
        for(auto&i : transactions){
            high+=(i[0]*1LL);
            low = max(low,i[0]*1LL);
            
            if(i[0] >= i[1])
                d +=i[0] - i[1];
        }
       
        
        while(low<=high){
            long long mid = low + ((high - low)/2);
            
            if(isPossible(transactions,mid,d)){
                ans = mid;
                high = mid-1;
            }
            
            else
                low = mid +1;
        }
        return ans;
        
        
    }
};