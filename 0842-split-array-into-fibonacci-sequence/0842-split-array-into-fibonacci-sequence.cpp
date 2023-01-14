class Solution {
public:
    
    bool backtrack(int curr,long long prev1,long long prev2,vector<int>&ans,string&num){
        
        if(curr>=num.size()) 
                return ans.size()>=3;
        
        long long temp = 0LL;
        for(int i=curr;i<num.size();i++){
            temp*=10LL;
            temp+=(num[i] - '0');
            
            if((num[curr]=='0' and temp>0)
               or (temp > INT_MAX)
               or(temp > (prev1 + prev2)*10LL))
                return false;
            
            if(temp == prev1 + prev2){
                ans.push_back(temp);
                if(backtrack(i+1,prev2,temp,ans,num))
                    return true;
                else
                    ans.pop_back();
            }
        
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string num) {
        
        vector<int>ans;
        long long prev1 = 0LL;
        for(int i=0;i<num.size();i++){
            prev1*=10LL;
            prev1+=(num[i] -'0');
            
            
            
            if((num[0]=='0' and prev1>0) or (prev1 > INT_MAX))
                break;
            //cout<<"i :"<<i<<" --> "<<prev1<<" ===> "<<endl;
            
            ans.push_back(prev1);
            
            long long prev2 = 0LL;
            
            for(int j=i+1;j<num.size();j++){
                
                prev2*=10LL;
                prev2+=(num[j] -'0');
                
                
                 if((num[i+1]=='0' and prev2>0) or (prev2 > INT_MAX))
                    break;
                
                //cout<<" j :"<<j<<" --> "<<prev2<<" : "<<endl;
                
                ans.push_back(prev2);

                if(backtrack(j+1,prev1,prev2,ans,num))
                    return ans;
                
                ans.pop_back();
            }
            ans.pop_back();
        }
        
        return ans;
        
        
    }
};