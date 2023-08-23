class Solution {
public:
    int count[26];
    
    int getMax(int prevChar){
        
        int res = -1,ans = -1;
        for(int i=0;i<26;i++){
            
            if(i!=prevChar && count[i]!=0 && count[i]>res){
                res = count[i];
                ans = i;
            }
        }
        
        count[ans]--;
        
        return ans;
    }
    
    int getMin(int prevChar){
        
        int res = 501,ans = -1;
        for(int i=0;i<26;i++){
            
            if(i!=prevChar && count[i]!=0 && count[i]<res){
                res = count[i];
                ans = i;
            }
        }
        
        count[ans]--;
        
        return ans;
    }
    
    string reorganizeString(string s) {
        
        int  n = s.size();
        memset(count,0,sizeof count);
        
        for(char&ch : s){
            
            count[ch - 'a']++;
            
            if(n&1){
                if(count[ch - 'a']-1>s.size()/2)
                    return "";
            }
            else{
                if(count[ch - 'a']>s.size()/2)
                    return "";   
            }
        }
        
        string ans = "";
        int prevChar = 27;
        
        while(ans.size()<n){
            
            ans+=(char)(getMax(prevChar) + 'a'); 
            prevChar = ans.back()  - 'a';
            
            if(ans.size() == n)
                break;
            
            ans+=(char)(getMin(prevChar) + 'a');
            prevChar = ans.back()  - 'a';
        }
        
        return ans;
        
    }
};