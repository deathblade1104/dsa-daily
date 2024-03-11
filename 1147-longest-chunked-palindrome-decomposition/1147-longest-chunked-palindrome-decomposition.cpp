class Solution {
public:
    int longestDecomposition(string text) {
        
        if(text == "")
            return 0;
        
        int ans = 1, n = text.size();

        string temp1 ="", temp2 = "";

        for(int i=0;i<n;i++){
            temp1+=text[i];
            temp2 = text.substr(n-i-1);

            if(temp1 == temp2 and i<n-1){
                string nxtText = text.substr(i+1,n - i- i -2);
                return 2 + longestDecomposition(nxtText);
            }
        }

        return ans;
        
    }
};