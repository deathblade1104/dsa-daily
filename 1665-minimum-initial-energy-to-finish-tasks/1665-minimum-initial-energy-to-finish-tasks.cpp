// class Solution {
// public:
    
//     struct myComp{
//         bool operator()(const vector<int>&t1, const vector<int>&t2){
            
//             int diff1 = t1[1] - t1[0],diff2 = t2[1] - t2[0];
//             return diff1>=diff2;
//         }
//     };
    

    
//     int minimumEffort(vector<vector<int>>& tasks) {
//         sort(tasks.begin(),tasks.end(),myComp());
//         int low = 1,high = 1e9,ans = -1;
        
//         while(low<=high){
            
//             int mid = low + ((high - low)/2);
            
//             if(isPossible(tasks,mid)){
//                 ans = mid;
//                 high = mid -1;
//             }
            
//             else low = mid + 1;
//         }
        
//         return ans;
        
//     }
// };

class Solution {
public:
    bool isPossible(vector<vector<int>>&tasks,int&mid){
        
        int rem = mid;
        for(vector<int>&task : tasks){
            
            if(rem<task[1])
                return false;
            
            rem-=task[0];
        }
        
        return true;
    }
    
    
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(), [&](vector<int>a, vector<int>b){
           return a[1]-a[0]>b[1]-b[0];
        });
        int maxi= 0;
        for(int i=0;i<tasks.size();i++) maxi=max(maxi,tasks[i][1]);
        int low=maxi,high=INT_MAX,ans=-1;
        
        while(low<=high){
             int mid= low + ((high - low)/2);
            if(isPossible(tasks,mid)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
       
    }

};