class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()>s2.size())
            return false;
        
      vector<int>count1(26,0),count2(26,0);
        
        for(char ch : s1)
            count1[ch-'a']++;
        
        for(int i=0;i<s1.size();i++)
            count2[s2[i]-'a']++;
        
        if(count1==count2)
            return true;
        
        for(int i=s1.size();i<s2.size();i++)
        {
            count2[s2[i-s1.size()]-'a']--;
            count2[s2[i]-'a']++;
            
            if(count1==count2)
              return true;            
        }
        
        return false;
        
        
        
        
    }
};