class Solution {
public:
    string minimizeStringValue(string s) {
        int cntBefore[26],cntAfter[26];
        string temp ="";
        memset(cntBefore,0,sizeof cntBefore);
        memset(cntAfter,0,sizeof cntAfter);
        
        
        for(char&ch : s){
            
            if(isalpha(ch))
                cntAfter[ch - 'a']++;
        }
        
        
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
            temp+=(char)(idx + 'a');
        }
        
        sort(temp.rbegin(),temp.rend());
        
        for(char&ch : s){
            if(ch == '?'){
                ch = temp.back();
                temp.pop_back();
            }
        }
        
        return s;
    }
};