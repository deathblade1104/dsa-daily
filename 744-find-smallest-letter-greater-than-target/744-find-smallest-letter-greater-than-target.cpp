class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n =letters.size()-1;
        if(target>=letters[n] or target<letters[0])
            return letters[0];
        
        int l=0,h=n,ans;
        
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
        
        return letters[ans];
    }
};