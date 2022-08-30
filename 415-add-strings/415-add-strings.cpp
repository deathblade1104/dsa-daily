class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        string ans="";
        int carry=0,i=0,j=0;
        
        while(i<num1.size() or j<num2.size() or carry==1)
        {
            int sum=carry;
            
            sum+=(i == num1.size()) ? 0 : num1[i++]-'0';
            sum+=(j == num2.size()) ? 0 : num2[j++] -'0';
            
            if(sum>=10)
                carry=1;
            
            else carry=0;
            
            sum%=10;
            
            ans+=(char)(sum+'0');
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};