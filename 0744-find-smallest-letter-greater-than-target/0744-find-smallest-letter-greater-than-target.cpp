class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n =letters.size()-1;
        
        int l=0,h=n,ans=-1;
        
        while(l<=h)
        {
            int mid = (l+h)/2;
            
            if(letters[mid]>target)
            {
                ans=mid;
                h=mid-1;
            }
            
            else l = mid+1;
        }
        
        return ans==-1? letters[0] : letters[ans];
    }
};