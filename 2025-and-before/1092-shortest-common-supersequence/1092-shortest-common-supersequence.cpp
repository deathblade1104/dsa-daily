class Solution {
public:
    string dp[1001][1001] ;
    int N, M;

    string helper(int curr1,int curr2,string&s1,string&s2){

        if(curr1>=N or curr2>=M)
            return "";

        if(dp[curr1][curr2]!="")
            return dp[curr1][curr2];

        if(s1[curr1]==s2[curr2])
            return dp[curr1][curr2]+=s1[curr1] + helper(curr1+1, curr2+1, s1, s2);

        string op1= helper(curr1+1,curr2,s1,s2);
        string op2 = helper(curr1, curr2+1, s1, s2);

        return dp[curr1][curr2] = (op1.size()>=op2.size())? op1 : op2;
    }
    
    
    string shortestCommonSupersequence(string str1, string str2) {
        N = str1.size();
        M = str2.size();
        
        
        string lcs = helper(0,0,str1,str2),ans ="";
        //cout<<"LCS is :"<<lcs<<endl;
        
        int i=0,j=0;
        
        for(char&ch : lcs){
            
           while (str1[i] != ch)
                ans += str1[i++];
            
            while (str2[j] != ch)
                ans += str2[j++];
            
            ans += ch, i++, j++;
        }
        
        return ans+ str1.substr(i) + str2.substr(j);
    }
};