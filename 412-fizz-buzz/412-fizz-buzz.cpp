class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string>ans(n);
        
        for(int i=1;i<=n;i++)
        {
            string curr="";
            bool flag = false;
            if(i%3==0)
            {
                curr+="Fizz";
                flag = true;
            }
            
            if(i%5==0){
                curr+="Buzz";
                flag = true;
            }
            
            if(!flag){
                curr+=to_string(i);
            }
            
            ans[i-1]=curr;
        }
        
        return ans;
        
    }
};