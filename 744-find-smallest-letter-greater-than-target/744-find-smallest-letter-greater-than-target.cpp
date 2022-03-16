class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target >= letters[letters.size()-1])
            return letters[0];
        
        if(target<letters[0])
            return letters[0];
        
        int l=0,h=letters.size()-1,ans;
        
        while(l<=h)
        {
            int mid = l + ((h-l)/2);
            
            if(letters[mid]<=target)
            {
                ans=mid;
                l=mid+1;
            }
            else
                h=mid-1;
        }
        
        return letters[ans+1];
        

    }
};