class Solution {
public:
    int upperBound(vector<int>&potions,int&currSpell,long long&success){
        
        
        int low = 0,high = potions.size() -1,ans=0;
        
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
        
        for(int&i : spells)
            ans.push_back(potions.size() - upperBound(potions,i,success));
        
        
        return ans;
        
    }
};