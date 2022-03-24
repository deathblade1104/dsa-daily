class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        
        int ans=0,l=0,h=people.size()-1;
        
        while(l<=h)
        {
            int first = people[l], second = people[h];
            
            if(first + second <=limit)
            l++;
                
            h--;
            ans++;
        }
        
        return ans;
        
    }
};