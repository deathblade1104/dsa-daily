class Solution {
public:
    unordered_map<int,vector<int>>mp;

    void primeFactorization(int n,int num) {
   

        // Handle the special case of 1
        if(n%2== 0){
            mp[2].push_back(num);
        }

        while (n % 2 == 0) {
            n /= 2;
        }

        
        for (int i = 3; i * i <= n; i += 2) {
            
            if(n%i== 0){
            mp[i].push_back(num);
            }
            
            while (n % i == 0) {
                n /= i;
            }
        }
        
        if(n>1)
            mp[n].push_back(num);
   
    }
    
    int findPar(int x,vector<int>&par){
        
        if(par[x] == x)
            return par[x];
        
        return par[x]= findPar(par[x],par);
    }
    
   void DSU(int a,int b,vector<int>&par,vector<int>&rank){
        
        int p1 = findPar(a,par),p2 = findPar(b,par);

        if(p1 == p2)
            return;

        if(rank[p1]>=rank[p2]){
           rank[p1]++;
           par[p2]= p1;
        }

        else{
           rank[p2]++;
           par[p1]= p2;
        }

        return;
    }
    
    
    bool canTraverseAllPairs(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n ==1)
            return true;
        
        for(int i=0;i<n;i++){
            
            if(nums[i] == 1)
                return false;
            
            primeFactorization(nums[i],i);
        }
        
        vector<int>par(n),rank(n);
        
        for(int i=0;i<n;i++){
            par[i] = i;
            rank[i] = 0;
        }
        
        
        for(auto&it :mp){
            for(int i=1;i<it.second.size();i++){
                DSU(it.second[i-1],it.second[i],par,rank);
            }
        }
        
        
        unordered_set<int>st;
        
        for(int i=0;i<n;i++){
            st.insert(findPar(i,par));
            if(st.size()>=2)
                return false;
        }
        
        return true;
    }
};