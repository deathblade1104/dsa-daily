class Solution {
public:
    int longestOnes(string&s, int&k,char ch) {
       int N = s.size(), cnt = 0, i = 0, ans = 0;
        for (int j = 0; j < N; ++j) {
            cnt += s[j] == ch;
            while (cnt > k) cnt -= s[i++] == ch; 
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        int op1 = longestOnes(answerKey,k,'F'), op2 = longestOnes(answerKey,k,'T');
        
        return max(op1,op2);
    }
};