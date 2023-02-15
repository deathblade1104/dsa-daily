class Solution {
public:
    vector<int> reverseNumber(int num){
        
        vector<int>ans;
        
        while(num){
            ans.push_back(num%10);
            num/=10;
        }
        
        //reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        reverse(num.begin(),num.end());
        vector<int>num2 = reverseNumber(k);
        
        vector<int>ans;
        int i=0,j=0,carry=0;
        
        while(i<num.size() and j<num2.size()){
            
            int currSum  = num[i] + num2[j] + carry;
            
            carry= currSum/10;
            currSum%=10;
            
            ans.push_back(currSum);
            i++,j++;
        }
        
        while(i<num.size()){
            
            int currSum  = num[i] + carry;
            
            carry= currSum/10;
            currSum%=10;
            
            ans.push_back(currSum);
            i++;
        }
        
        while(j<num2.size()){
            
            int currSum  = num2[j] + carry;
            
            carry= currSum/10;
            currSum%=10;
            
            ans.push_back(currSum);
            j++;
        }
        
        if(carry)
            ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};