class Solution {
public:
    
    void helper(string&s,char ch,int&i,int&sum,int&currIndex){
        
        int curr=0;
        for(char&c :s){
            curr+=(ch == c);
        }
        
        
        if(curr>0)
            i=currIndex;
        
        
        sum+=curr;
        
        return;
        
    }
    
    int getAns(int i,int&sum,vector<int>&travel){
        
        if(i<0)
            return 0;
        
        return travel[i] + sum;
    }
    
    int garbageCollection(vector<string>& v, vector<int>& travel) {
        
        
        int n = v.size();
        
        reverse(travel.begin(),travel.end());
        travel.push_back(0);
        reverse(travel.begin(),travel.end());

        
        int sum1=0,sum2=0,sum3=0,i1=-1,i2=-1,i3=-1;
        
        for(int i=0;i<n;i++){
            
            helper(v[i],'G',i1,sum1,i);
            helper(v[i],'P',i2,sum2,i);
            helper(v[i],'M',i3,sum3,i);
            
            if(i>0){
                travel[i]+=travel[i-1];
            }
        }
        
        int op1 = getAns(i1,sum1,travel);
        int op2 = getAns(i2,sum2,travel);
        int op3 = getAns(i3,sum3,travel);
        
        return op1+op2+op3;
        
    }
};