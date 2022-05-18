class Solution {

public:
    int strStr(string text, string pattern) {
        
        int q = 101;
        int m = pattern.size();
        int n = text.size();
        int i, j, hash_p = 0, hash_t = 0, h = 1, d = m + n;

        for (i = 0; i < m - 1; i++)
            h = (h * d) % q;


        // Calculate hash value for pattern and text
        for (i = 0; i < m; i++) 
        {
            hash_p = (pattern[i] + d * hash_p) % q;
            hash_t = (text[i] + d * hash_t) % q;
        }

        // Find the match
        for (i = 0; i <= n - m; i++) 
        {

        // Check the hash values of current windows of text and pattern.
            if (hash_p == hash_t) 
            {

                for (j = 0; j < m; j++) 
                {
                    if (text[i + j] != pattern[j]) 
                    break;
                }
                if (j == m) 
                return i;
            }


            if (i < n - m) 
            {
                hash_t = (d * (hash_t - text[i] * h) + text[i + m]) % q;

                //converting negative value of hash_t to positive.
                if (hash_t < 0)
                    hash_t = (hash_t + q);
            }



        }
    
     
        return -1;
    }
        

};