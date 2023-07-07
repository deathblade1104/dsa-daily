class Solution {
public:
    
    int helper(string&s,int&k,char ch){
        
        int ans = 0,z=0,start = 0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]!=ch)
                z++;
            
            while(z>k){
                if(s[start] != ch)
                    z--;
                
                start++;
            }
            
            ans = max(ans,(i - start + 1));
        }
        
        return ans;
    }
    
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        return max(helper(answerKey,k,'F'),helper(answerKey,k,'T'));
    }
};