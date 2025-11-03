class Solution {
public:
    string minimizeStringValue(string s) {
        int cntBefore[26],cntAfter[26];
        memset(cntBefore,0,sizeof cntBefore);
        memset(cntAfter,0,sizeof cntAfter);
                
        for(char&ch : s){
            
            if(isalpha(ch))
                cntAfter[ch - 'a']++;
        }
        
        priority_queue<char,vector<char>,greater<char>>pq;
        
        for(char&ch : s){
            
            if(isalpha(ch)){
                cntBefore[ch - 'a']++;
                cntAfter[ch - 'a']--;
                continue;
            }
            
            int maxi = 1e9, idx = -1;
            
            for(int i=0;i<26;i++){
                if(cntBefore[i] + cntAfter[i] + 1 <maxi){
                    maxi = cntBefore[i] + cntAfter[i] + 1;
                    idx = i;
                }
            }
            
            cntBefore[idx]++;
            pq.push((char)(idx + 'a'));
        }
    
        
        for(char&ch : s){
            if(ch == '?'){
                ch = pq.top();
                pq.pop();
            }
        }
        
        return s;
    }
};