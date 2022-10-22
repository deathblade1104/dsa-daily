class Solution {
public:

    int palinDP[2001][2001];
    
    int isPalinHelper(int i,int j, string &s){
        
        if(i==j)
            return palinDP[i][j] = true;
        if(i == j-1)
            return palinDP[i][j] = (s[i]==s[j])? true : false;
        
        if(palinDP[i][j]!=-1)
            return palinDP[i][j];
        
        bool ans = false;
        
        if(s[i] == s[j])
            ans = true & isPalinHelper(i+1,j-1,s);
        
        bool x = isPalinHelper(i+1,j,s) , y = isPalinHelper(i,j-1,s);
        
        return palinDP[i][j] = ans;
    }

    bool checkPartitioning(string s) {
        
        if(s.size() == 3)
            return true;
        
        memset(palinDP,-1,sizeof palinDP); 
        int x = isPalinHelper(0,s.size()-1,s), N = s.size();
        
        for (int i = 1; i < N - 1; ++i) {
	        for (int j = i; j < N - 1; ++j) {
		        if (palinDP[0][i - 1] && palinDP[i][j] && palinDP[j + 1][N - 1]) 
                    return true;
	        }
        }
        
        return false;
    }
};