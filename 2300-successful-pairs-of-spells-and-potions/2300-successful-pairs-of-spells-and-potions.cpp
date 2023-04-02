class Solution {
public:
    int upperBound(vector<int>&potions,int&n,int&currSpell,long long&success){
        
        
        int low = 0,high = n - 1,ans=0;
        
        while(low<=high){
            int mid = low + ((high -low)/2);
            long long currSuccess = 1LL * potions[mid] *  currSpell;
            
            if(currSuccess<success){
                low = ans = mid + 1;
            }
            
            else{
                high = mid -1;
            }
        }
        
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(),potions.end());
        vector<int>ans;
        int n = potions.size();
        for(int&i : spells)
            ans.push_back(n - upperBound(potions,n,i,success));
        
        
        return ans;
        
    }
};