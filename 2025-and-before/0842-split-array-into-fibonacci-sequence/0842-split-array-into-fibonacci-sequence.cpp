class Solution {
public:
    bool check(int startIdx,long long currNum, string&s, long long lim1 = INT_MAX*1LL, long long lim2 = INT_MAX*1LL){
        
        if(s[startIdx] == '0' and currNum>0)
            return false;
        
        if(currNum>lim1 or currNum>lim2)
            return false;
        
        return true;
        
    }
    bool backtrack(int curr,long long prev1,long long prev2,vector<int>&ans,string&num){
        
        if(curr>=num.size()) 
                return ans.size()>=3;
        
        long long temp = 0LL;
        for(int i=curr;i<num.size();i++){
            temp*=10LL;
            temp+=(num[i] - '0');
            
            if(!check(curr,temp,num,(10LL * (prev1 + prev2))))
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
            
        
            if(!check(0,prev1,num))
                break;
            
            //cout<<"i :"<<i<<" --> "<<prev1<<" ===> "<<endl;
            
            ans.push_back(prev1);
            
            long long prev2 = 0LL;
            
            for(int j=i+1;j<num.size();j++){
                
                prev2*=10LL;
                prev2+=(num[j] -'0');
                
                if(!check(i+1,prev2,num))
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