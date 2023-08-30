class Solution {
public:
    string str;
    bool isSubsequence(string&s1,string&s2){
        
        int i=0,j=0;
        
        while(i<s1.size()&& j<s2.size()){
            
            if(s1[i]==s2[j])
                j++;
            
            i++;
        }
        
        return j==s2.size();
    }
    
    bool isPossible(string &s,int&mid,vector<int>&arr,string&s2){
        
        for(int i=0;i<mid;i++){
            s[arr[i]] = '.';
        }
        
        return isSubsequence(s,s2);
    }
    int maximumRemovals(string s, string p, vector<int>& arr) {
        
        str = s;
        int low = 1, high = arr.size(),ans = 0;
        
        while(low<=high){
            s = str;
            int mid = low + ((high - low)/2);
            
            if(isPossible(s,mid,arr,p)){
                ans = mid;
                low = mid + 1;
            }
            
            else high = mid -1;
        }
        
        return ans;
        
    }
};