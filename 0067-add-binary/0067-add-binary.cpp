class Solution {
public:
    
    string getSum(string&s1,string&s2){
        
        string ans ="";
        int carry = 0;
        
        
        int i=s1.size()-1,j=s2.size()-1;
        
        while(i>=0 and j>=0){
            
            
            int currSum = carry + s1[i] -'0' + s2[j] -'0';
            
            if(currSum>=2){
                carry =1;
                currSum = currSum%2;
            }
            else carry=0;
            
            ans+=to_string(currSum);
            i--;
            j--;
        }
        
        while(i>=0){
            
            
            int currSum = carry + s1[i] -'0';
            
            if(currSum>=2){
                carry =1;
                currSum = currSum%2;
            }
            else carry=0;
            
            ans+=to_string(currSum);
            i--;
        }
        
        
         while(j>=0){
            
            
            int currSum = carry + s2[j] -'0';
            
            if(currSum>=2){
                carry =1;
                currSum = currSum%2;
            }
             
            else carry=0;
            
             ans+=to_string(currSum);
            j--;
        }
        
        if(carry == 1)
            ans+='1';
        
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string addBinary(string a, string b) {
        
        return getSum(a,b);
    }
};