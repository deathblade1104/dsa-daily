class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
                
        string temp = countAndSay(n-1),ans="";
        
        int count = 1;
        char curr=temp[0];
        
        for(int i=1;i<temp.size();i++){
            
            if(temp[i] == curr)
                count++;
            
            else{
                ans+=to_string(count) + curr;
                count=1;
                curr = temp[i];
            }
        }
        
        ans+=to_string(count) + curr;
        
        return ans;
    }
};