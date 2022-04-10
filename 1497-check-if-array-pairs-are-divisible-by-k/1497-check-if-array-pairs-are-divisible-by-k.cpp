class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int count=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++)
        {
            int rem = ((arr[i]%k)+k)%k;
            
            if(rem==0)
            {
                if(mp.count(0)==1 and mp[0]>=1)
                {
                    mp[0]--;
                    count++;
                }
                
                else
                    mp[0]++;
                
            }
            
            else
            {
                if(mp.count(k-rem)==1 and mp[k-rem]>=1)
                {    
                        count++;
                        mp[k-rem]--;
                    
                }
                
                else
                    mp[rem]++;
            }
        }
        
        return (count==arr.size()/2);
    }
};