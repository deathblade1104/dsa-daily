class Solution {
public:
    
    bool isValid(string&s){
        
        if(s.size()>3)
            return false;
        
        if(s[0] == '0' and s.size()>1)
            return false;
        
        if(stoi(s)>255)
            return false;
        
        return true;
    }
    
    
    string stringMaker(string&s1,string&s2,string&s3,string&s4){
        
        return s1+"."+s2+"."+s3+"."+s4;
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        vector<string>ans;
        
        string first="";
        for(int i=0;i<3;i++){
             first+=s[i];
            
            if(!isValid(first))
                continue;
            
            string second ="";
            
            for(int j=i+1;j-i<=3 and j<s.size();j++){
                second += s[j];
                
                if(!isValid(second))
                    continue;
                
                
                string third ="";
                for(int k=j+1;k-j<=3 and k<s.size();k++){
                    third += s[k];
                    
                    if(!isValid(third))
                        continue;
                    
                    
                    string fourth = "";
                    
                    for(int l=k+1;l-k<=3 and l<s.size();l++){
                    
                        fourth+=s[l];
                        
                        if(!isValid(fourth))
                            continue;
                        
                        if(l==s.size()-1)
                        ans.push_back(stringMaker(first,second,third,fourth));
                        
                    }
                }
            }
        }
        
        return ans;
        
        
        
    }
};