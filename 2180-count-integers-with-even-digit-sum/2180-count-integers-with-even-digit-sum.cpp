class Solution {
public:
    int countEven(int num) {
        if(num<2)
            return 0;
        
        if(num<=10)
        {
            int ans=0;
            for(int i=2;i<=num;i+=2)
                ans++;
            
            return ans;
        }
        
        
        int ans=0,div=num/10,sum=0,var=num%10;
        
        if(div>0)
            ans+=4 + ((div-1)*5);
        
        while(div!=0)
            sum+=div%10,div/=10;
        
        if(sum&1)
        {
            for(int i=1;i<=var;i+=2)
                ans++;
        }
        
        else
        {
            for(int i=0;i<=var;i+=2)
                ans++;
        }
        
        return ans;
        
        
    }
};