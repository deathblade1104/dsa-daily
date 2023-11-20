class Solution {
public:
    static const int maxN = 1e5+1;
    int arr1[maxN],arr2[maxN],arr3[maxN];
    
    void helper(string&s,char ch,int&i,int arr[maxN],int&currIndex){
        
        int curr=0;
        for(char&c :s){
            curr+=(ch == c);
        }
        
        
        if(curr>0)
            i=currIndex;
        
        
        arr[currIndex] = curr;
        
        return;
        
    }
    
    int getAns(int i,int arr[maxN],vector<int>&travel){
        
        if(i<0)
            return 0;
        
        return travel[i] + arr[i];
    }
    
    int garbageCollection(vector<string>& v, vector<int>& travel) {
        
        
        int n = v.size();
        
        reverse(travel.begin(),travel.end());
        travel.push_back(0);
        reverse(travel.begin(),travel.end());

        memset(arr1,0,sizeof arr1);
        memset(arr2,0,sizeof arr2);
        memset(arr3,0,sizeof arr3);
        
        int i1=-1,i2=-1,i3=-1;
        
        for(int i=0;i<n;i++){
            
            helper(v[i],'G',i1,arr1,i);
            helper(v[i],'P',i2,arr2,i);
            helper(v[i],'M',i3,arr3,i);
            
            if(i>0){
                arr1[i]+=arr1[i-1];
                arr2[i]+=arr2[i-1];
                arr3[i]+=arr3[i-1];
                travel[i]+=travel[i-1];
            }
        }
        
        int op1 = getAns(i1,arr1,travel);
        int op2 = getAns(i2,arr2,travel);
        int op3 = getAns(i3,arr3,travel);
        
        return op1+op2+op3;
        
    }
};