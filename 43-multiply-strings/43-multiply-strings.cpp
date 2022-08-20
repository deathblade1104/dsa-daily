class Solution {
public:
    string findSum(string X, string Y) {
        // Your code goes here
        
        if(X=="")
            return Y;
        
        reverse(X.begin(),X.end());
        reverse(Y.begin(),Y.end());
        
        int carry=0,i=0,j=0,n=X.size(),m=Y.size();
        string ans ="";
        
        while(i<n or j<m or carry){
            
            int sum = carry;
            
            if(i<n){
                // cout<<X[i]<<"+"<<" ";
                sum+=X[i] - '0';
                i++;
            }
            
            if(j<m){
                // cout<<Y[j]<<"+"<<" ";
                sum+=Y[j] -'0';
                j++;
            }
            
            
            if(sum>=10){
                carry=1;
                sum%=10;
            }
            else carry =0;
            
            // cout<<" == "<<sum;
            ans+=(char)(sum%10 + '0');
            
            // cout<<sum<<"-->"<<ans<<endl;
            
            // cout<<"==>"<<ans<<endl;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string mul(string&s1,string&s2){
        
        string before ="";
        
        for(int i=0;i<s2.size();i++){
            
            string after="";
            int z =i;
            
            while(z--)
                after+="0";
            
            int carry = 0;
            // cout<<after<<endl;
            
            for(int j=0;j<s1.size();j++){
                
                // cout<<s2[i]<<" * "<<s1[j]<<endl;
                
                int curr_mul = (s2[i] -'0') *(s1[j] - '0') + carry;
                
                after+=(char)((curr_mul%10) + '0');
                carry= curr_mul/10;
                
                // cout<<j<<" : "<<after<<endl;
            }
            
            if(carry!=0)
            after+=(char)((carry%10) + '0');
            
            // cout<<after<<" _ "<<before<<endl;
            
            reverse(after.begin(),after.end());
            
            before = findSum(before,after);
            
            
        }
        
        return before;
    }
    
    string multiply(string num1, string num2) {
        
        if(num1=="0" or num2=="0")
            return "0";
        
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
                
        string ans ="" ;
        
        if(num1.size()>=num2.size())
            ans = mul(num1,num2);
        
        else ans = mul(num2,num1);
        
        // reverse(ans.begin(),ans.end());
        
        return ans;
    }
};