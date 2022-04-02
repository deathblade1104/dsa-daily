class Solution {
public:
    bool get_ans(string s, int l, int h,bool &deleted)
    {
        while(l<=h)
        {
            if(s[l]==s[h])
            {
                l++;
                h--;
            }
            
            else
            {
                if (deleted) return false;
                deleted = true;
                
                return get_ans(s,l+1,h,deleted) | get_ans(s,l,h-1,deleted);
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        bool deleted=false;
        return get_ans(s,0,s.size()-1,deleted);
    }
};