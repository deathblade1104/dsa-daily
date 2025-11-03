class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string>st;
        
        for(string&str : words){
            string temp ="";
            
            for(char&ch : str)
             temp+=arr[ch -'a'];
            
            st.insert(temp);
        }
        
        return st.size();
        
    }
};