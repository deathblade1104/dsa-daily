class Solution {
public:
    
    string getString(vector<string>&arr){
        
        string s ="";
        
        for(string&str : arr)
            s+=str;
        
        return s;
    }
    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        return getString(word1) == getString(word2);
    }
};