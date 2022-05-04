class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        int count=0;
        
        for(int i : nums)
        {
            if(mp.count(k-i)==1)
            {
                count++;
                
                if(mp[k-i]==1)
                    mp.erase(k-i);
                else mp[k-i]--;
            }
            
            else mp[i]++;
        }
        
        return count;
    }
};