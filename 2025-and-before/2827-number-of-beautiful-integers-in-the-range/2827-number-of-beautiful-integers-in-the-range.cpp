class Solution {
public:
    int n,k;
    string s;
    int dp[10][2][2][20][6][6];
    
    int helper(int curr,bool hasStarted,bool tight,int modK,int odd,int even){
        
        if(curr>=n){    
            return hasStarted && modK==0 && even==odd;
        }
        
       int& ans = dp[curr][hasStarted][tight][modK][odd][even];

        
        if(ans!=-1)
            return ans;
        
        int upperLimit = tight? s[curr] -'0' : 9;
        ans = 0;
        
        for(int i=0;i<=upperLimit;i++){
            int newModK = (modK*10 + i)%k;
            int newOdd = odd+ (i&1),newEven = even + ((hasStarted||i>0) && (i%2==0));
            
            if(abs(newOdd - newEven)>5 || newOdd>5 || newEven>5)
                continue;
                
            
            ans+=helper(curr+1,hasStarted|i>0,tight&i==upperLimit,newModK,newOdd,newEven);
        }
        return ans;
    }
    
    int numberOfBeautifulIntegers(int low, int high, int K) {
        
        low--;
        int ans = 0;
        k=K;
        
        if(low>0){
            memset(dp,-1,sizeof dp);
            s = to_string(low);
            n = s.size();
            ans-=helper(0,0,1,0,0,0);
        }

        memset(dp,-1,sizeof dp);
        s = to_string(high);
        n = s.size();
        ans+=helper(0,0,1,0,0,0);
        
        return ans;
    }
};