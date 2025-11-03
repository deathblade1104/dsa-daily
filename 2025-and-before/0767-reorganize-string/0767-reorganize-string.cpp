class Solution {
public:
    int count[26];

    string reorganizeString(string s) {
    
        int  n = s.size();
        memset(count,0,sizeof count);
        
        for(char&ch : s){
            count[ch - 'a']++;
        }
        
        string ans = "";
        int prevChar = 27,prevCount=-1;
        priority_queue<array<int,2>>pq;
        
        for(int i=0;i<26;i++){
            if(count[i])
                pq.push({count[i],i});
        }
        
        while(pq.size()){
            
            array<int,2>curr= pq.top();
            pq.pop();
            
            if(prevChar!=27)
                pq.push({prevCount,prevChar});
            
            ans+=(char)(curr[1]+'a');
            curr[0]--;
            
            if(curr[0]){
                prevChar = curr[1];
                prevCount = curr[0];
            }
            else prevChar = 27;
        }
        
        if(ans.size() != n)
            return "";
        
        return ans;
            
        
    }
};