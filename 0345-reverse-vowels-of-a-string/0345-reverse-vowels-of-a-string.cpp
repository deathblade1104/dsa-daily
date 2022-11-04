class Solution {
public:
    
    bool isVowel(char ch){
        
        if(ch =='A' or ch =='a')
            return true;
        
        else if(ch =='E' or ch =='e')
            return true;
        
       else if(ch =='I' or ch =='i')
            return true;

       else if(ch =='O' or ch =='o')
            return true;
        
        else if(ch =='U' or ch =='u')
            return true;
        
        else
        return false;

    }
    string reverseVowels(string&s) {
        
        
        stack<char>st;
        
        for(char&ch: s){
            if(isalpha(ch) and isVowel(ch))
                st.push(ch);
        }
        
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i] = st.top();
                st.pop();
            }
        }
        
        return s;
        
    }
};