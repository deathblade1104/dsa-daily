class Solution {
public:
    bool isVowel(char ch){
        
        int asciiVal =(int)(ch - 'a');
        if (asciiVal<0)
            asciiVal+=32;
        
        ch = (char)(asciiVal + 'a');
        
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    int count[128];
    string getSorted(){
        
        string ans = "";
        
        for(int i=0;i<128;i++){
            
            while(count[i]--){
                ans+=(char)(i);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string sortVowels(string s) {
        
        memset(count,0,sizeof count);
        for(char&ch : s){
            if(isVowel(ch)){
                count[ch]++;
            }
        }
        
        
        string ans = "",sortedStr = getSorted();
        
        
        for(char&ch : s){
            if(!isVowel(ch))
                ans+=ch;
            
            else {
                ans+=sortedStr.back();
                sortedStr.pop_back();
            }
        }
        
        return ans;    
    }
};