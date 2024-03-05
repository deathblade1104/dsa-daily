// class Solution {
// public:
    
//     struct myComp{
//         bool operator()(const vector<int>&t1, const vector<int>&t2){
            
//             int diff1 = t1[1] - t1[0],diff2 = t2[1] - t2[0];
//             return diff1>=diff2;
//         }
//     };
    
//     bool isPossible(vector<vector<int>>&tasks,int mid){
        
//         for(vector<int>&task : tasks){
            
//             if(task.size()>=2){
//                 if(task[1]>mid)
//                     return false;
//             }
            
            
            
//             mid-=task[0];
//         }
        
//         return true;
//     }
    
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
    bool check(int m, vector<vector<int>>&tasks){
        int rem=m;
        for(int i=0;i<tasks.size();i++){
            if(rem>=tasks[i][1]) rem-=tasks[i][0];
            else return false;
        }
        return true;
        
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(), [&](vector<int>a, vector<int>b){
           return a[1]-a[0]>b[1]-b[0];
        });
        int maxi= INT_MIN;
        for(int i=0;i<tasks.size();i++) maxi=max(maxi,tasks[i][1]);
        int low=maxi;
        int high=INT_MAX;
        int ans;
        
        while(low<=high){
             int mid= low + ((high - low)/2);
            if(check(mid,tasks)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
       
    }

};