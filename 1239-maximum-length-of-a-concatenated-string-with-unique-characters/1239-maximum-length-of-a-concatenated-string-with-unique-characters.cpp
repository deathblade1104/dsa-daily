class Solution {
public:
    bool checker[26];
    bool check_unique(string s){
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
    void helper(int curr,vector<string>&arr,unordered_map<char,int>&mp,int&ans){
        
        if(curr == arr.size()){
            ans = max(ans,(int)mp.size());
            return;
        }
        
        
        
        if(check_unique(arr[curr]) and isPossible(mp,arr[curr])){
            
            for(char&ch : arr[curr])
            mp[ch]++;
        
            helper(curr+1,arr,mp,ans);

            for(char&ch : arr[curr]){

                if(mp[ch]==1)
                    mp.erase(ch);

                else
                    mp[ch]--;
            }
        }
        
        helper(curr+1,arr,mp,ans);
        
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        unordered_map<char,int>mp;
        
        helper(0,arr,mp,ans);
        
        return ans;
        
    }
};