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
    string reverseVowels(string s) {
        
        
        stack<char>st;
        
        for(char&ch: s){
            if(isalpha(ch) and isVowel(ch))
                st.push(ch);
        }
        
        string ans ="";
        
        
        for(char&ch : s){
            
            if(isalpha(ch) and isVowel(ch)){
                ans+=st.top();
                st.pop();
            }
            
            else
                ans+=ch;
        }
        
        return ans;
        
    }
};