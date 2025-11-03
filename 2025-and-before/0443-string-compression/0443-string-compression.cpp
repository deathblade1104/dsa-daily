class Solution {
public:
    int compress(vector<char>& chars) {
        
        int prevChar = chars[0],count=1,itr=0;
        
        for(int i=1;i<chars.size();i++){
            
            if(chars[i]!=prevChar){
                chars[itr++]=prevChar;
                
                if(count>1){
                 string c = to_string(count);
                    reverse(c.begin(),c.end());

                    while(c.size()>0){
                        chars[itr++]=c.back();
                        c.pop_back();
                    }
                }
                
                count=1;
                prevChar=chars[i];
            }
            
            else
                count++;
        }
        
        
       chars[itr++]=prevChar;
        
        if(count>1){
            string c = to_string(count);
            reverse(c.begin(),c.end());

            while(c.size()>0){
                chars[itr++]=c.back();
                c.pop_back();
            }
            
            while(chars.size()>itr)
                chars.pop_back();
        }
        
        return itr;
    }
};