class Solution
{
    public:
        int prefix[100001],suffix[100001];
        string pushDominoes(string dominoes)
        {
            int n = dominoes.size();
            memset(prefix,0,sizeof prefix);
            memset(suffix,0,sizeof suffix);

            int i = 0;
            while (i < n)
            {
                if(dominoes[i] == 'R')
                {
                    prefix[i++]+=1;
                    while (i < n and dominoes[i] == '.')
                    {
                        prefix[i] += 1 + prefix[i - 1];
                        i++;
                    }
                }
                else
                    i++;
            }

            i = n - 1;

            while (i >= 0)
            {
                if (dominoes[i] == 'L')
                {
                    suffix[i--] += 1;
                    while (i >= 0 and dominoes[i] == '.')
                    {
                        suffix[i] += 1 + suffix[i + 1];
                        i--;
                    }
                }
                else
                    i--;
            }
            
            
            string ans = "";
            for(int i=0;i<n;i++){
                
                if(suffix[i] == prefix[i])
                    ans+=dominoes[i];
                
                else if(!suffix[i] and prefix[i])
                    ans+='R';
                
                else if(suffix[i] and !prefix[i])
                    ans+='L';
                
                else {
                    
                    if(suffix[i]>prefix[i])
                        ans+='R';
                    
                    else
                        ans+='L';
                }
            }
            
            return ans;
        }
};