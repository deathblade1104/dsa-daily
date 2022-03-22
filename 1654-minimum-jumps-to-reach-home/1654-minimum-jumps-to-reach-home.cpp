class Solution {
public:
    int minimumJumps(vector<int>& f, int a, int b, int x) {
        
        vector < int  > v(10000 , 0);
         for(int i = 0; i< f.size(); i++){
             v[f[i]] =1;
             }
           queue <  pair < int  , int  >> q;
            q.push({0, 1});
         int ans = 0;
          while(q.size() > 0){
               int s =  q.size();
               while(s--){
                     auto node =  q.front();
                    q.pop();
                    int index  =   node.first;
                     int prev =  node.second;
                      if(index ==  x) return ans;
                     if(v[index] == 1) continue;
                       v[index] =1;
                    if(prev == 1 && (index-b)   >=  0){
                        q.push({(index-b) , 0}); 
                     }
                   if((index+a) <= 6000){
                           q.push({(index+a) , 1});
                      }
                    
                      
               }
                ans++;
          }
         return -1;
    }
    
};