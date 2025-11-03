class Solution {
public:

    int getMaxChar(vector<int>&arr)
    {
        int curr=0;
        
        for(int i=0;i<26;i++)
            if(arr[i]>curr)
                curr=arr[i];
        
        return curr;
    }
    
    int characterReplacement(string s, int k) {
        vector<int>arr(26,0);
        int start=0,ans=0,maxchar=0;
        
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-65]++;
            
            if(arr[s[i]-65]>maxchar)
                maxchar = arr[s[i]-65];
           
            while(i+1-start - maxchar >k and start<i)
            {
                arr[s[start]-65]--;
                start++;
                
                maxchar= getMaxChar(arr);
            }

            ans= max(ans,i-start+1);

        }
        
        return ans;
    }
};