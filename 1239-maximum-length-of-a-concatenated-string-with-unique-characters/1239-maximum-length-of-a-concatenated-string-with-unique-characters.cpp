class Solution {
public:
    bool checker[26];
    bool checkUnique(string s){
        memset(checker,false,sizeof checker);
        
        for(char ch : s){
            
            if(checker[ch-'a'])
                return false;
            
            checker[ch-'a'] = true;
        }
        
        return true;
    }
    
    bool isPossible(unordered_map<char,int>&mp,string s){
        for(char ch : s){
            if(mp.count(ch))
                return false;
        }
        
        return true;
    }
    
    void helper(int curr,vector<string>&arr,vector<bool>hasUnique,unordered_map<char,int>&mp,int&ans){
        
        if(curr == arr.size()){
            ans = max(ans,(int)mp.size());
            return;
        }
        
        if(hasUnique[curr] and isPossible(mp,arr[curr])){
            
            for(char&ch : arr[curr])
            mp[ch]++;
        
            helper(curr+1,arr,hasUnique,mp,ans);

            for(char&ch : arr[curr]){

                if(mp[ch]==1)
                    mp.erase(ch);

                else
                    mp[ch]--;
            }
        }
        
        helper(curr+1,arr,hasUnique,mp,ans);
        
    }
    int maxLength(vector<string>& arr) {
        int ans = 0,n= arr.size();
        unordered_map<char,int>mp;
        vector<bool>hasUnique(n);
        
        for(int i=0;i<n;i++)
            hasUnique[i] = checkUnique(arr[i]);
        
        helper(0,arr,hasUnique,mp,ans);
        
        return ans;
        
    }
};