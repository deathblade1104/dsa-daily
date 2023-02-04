class Solution {
public:
    //Sliding Window + Hashing
    
    bool isSame(int count1[],int count2[]){
        
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i])
                return false;
        }
        
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        
        if(s2.size()<s1.size())
            return false;
        
        int count1[26];
        int count2[26];
        
        
        
        memset(count1,0,sizeof count1);
        memset(count2,0,sizeof count2);
        
        
        for(char&ch : s1){
            count1[ch-'a']++;
        }
        
        for(int i=0;i<s1.size();i++){
            count2[s2[i] - 'a']++;
        }
        
        if(isSame(count1,count2))
            return true;
    
        for(int i=s1.size();i<s2.size();i++){
            
            count2[s2[i] - 'a']++;
            count2[s2[i - s1.size()] -'a']--;
        
            if(isSame(count1,count2))
                return true;
        }
        
        return false;
        
    }
};