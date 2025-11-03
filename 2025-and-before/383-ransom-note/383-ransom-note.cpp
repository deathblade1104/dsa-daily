class Solution {
public:
    bool canConstruct(string ransomNote, string magzine) {
        
        if(ransomNote.size()>magzine.size())
            return false;
        
        vector<int>counter(26,0);
        
        for(char& ch : magzine)
            counter[ch-'a']++;
        
        for(char& ch : ransomNote)
            counter[ch-'a']--;
        
        
        for(int&i : counter)
            if(i<0)
                return false;
        
        return true;
        
        
        
    }
};