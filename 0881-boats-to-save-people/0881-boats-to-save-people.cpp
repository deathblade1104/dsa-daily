class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());
        
        int ans=0,curr=0,l=0,h = people.size() - 1;
        
        
        while(l<=h){
            if(people[l] + people[h] <= limit)
                l++;
            
            h--;
            ans++;
        }
        
        
        return ans;
        
        
    }
};