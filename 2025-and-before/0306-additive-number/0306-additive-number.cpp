class Solution {
public:
    
    string addStrings(string&s1,string&s2){
        
        if(s1=="0") 
            return s2;
        
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        
        int carry = 0,n1 = s1.size(),n2 = s2.size();
        string ans ="";
        
        for(int i=0;i<max(n1,n2);i++){
            
            int currSum = carry;
            
            if(i<n1)
                currSum+=(s1[i] - '0');
            
            if(i<n2)
                currSum+=(s2[i] - '0');
            
            ans+=(char)(currSum%10 + '0');
            carry=currSum/10;
        }
        
        if(carry)
            ans+="1";
        
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
    
    bool backtrack(int curr, string&num,string&prev2,string&currSum,int count){
        
        if(curr>=num.size())
            return count>=3;
        
        for(int i=curr;i<num.size();i++){
            
            string temp = num.substr(curr,i-curr+1);
            
            if(temp[0] == '0' and temp.size()>1)
                return false;
            
            if(temp.size()>currSum.size())
                 return false;
            
            string currAdd = addStrings(prev2,temp);
            
            //cout<<"__k : "<<i<<" -- "<<temp<<" |--> "<<currAdd<<endl;
            
            if(temp == currSum){
                
                //cout<<"Getting in :"<<endl;
                
                if(backtrack(i+1,num,temp,currAdd,count+1))
                    return true;
            }    
        }
        
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        
        for(int i=0;i<min((int)num.size(),18);i++){
            
            string prev1 = num.substr(0,i+1);
            
            if(prev1[0] == '0' and prev1.size()>1)
                 return false;
            
            //cout<<"i : "<<i<<" -- "<<prev1<<" ===>"<<endl;
            
            for(int j=i+1;j<min(19,(int)num.size());j++){
                
                string prev2 = num.substr(i+1,j-i);
                
                if(prev2[0] == '0' and prev2.size()>1)
                    continue;
                
                string currSum = addStrings(prev1,prev2);
                
                //cout<<"_j : "<<j<<" -- "<<prev2<<" |-->"<<currSum<<endl;
                
                if(backtrack(j+1,num,prev2,currSum,2))
                    return true;
            }
        }
        
        return false;
        
    }
};