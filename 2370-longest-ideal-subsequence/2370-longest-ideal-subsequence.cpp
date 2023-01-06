class Solution {
public:
    int count[26];
    int longestIdealString(string s, int k) {
        
        memset(count,0,sizeof(count));
        int n = s.size(),ans=0;

        for(int i=0;i<n;i++){
            
            int currChar = s[i] - 'a',curr=0;
            // start = currChar - k + 26,end = currChar + k;
            // cout<<s[i]<<" : "<<endl;
            // start%=26;
            // end%=26;
            // cout<<start<<" __ "<<end<<endl;
            for(int j=0;j<26;j++){
                if(abs(j - currChar)<=k)
                curr = max(curr,1 + count[j]);
                
                //cout<<(char)(j+'a')<<" ----> "<<1 + count[j]<<" :: "<<curr<<endl;
            }
            
            count[currChar] = max(count[currChar],curr);
            ans = max(ans,count[currChar]);
            //cout<<"currAns ==>"<<ans<<endl;
        }
        
        return ans;
    }
};