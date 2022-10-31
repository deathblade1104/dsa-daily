class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size(),n = matrix[0].size();
        
        for(int c1=0;c1<n;c1++){
            int r = 0,c=c1;
            
            unordered_set<int>st;
            
            while(r<m and c<n){
                
                st.insert(matrix[r][c]);
                
                if(st.size()>=2)
                    return false;
                
                r++;
                c++;
            }
            
        }
        
        for(int r1=1;r1<m;r1++){
            int r = r1,c=0;
            
            unordered_set<int>st;
            while(r<m and c<n){
                
                st.insert(matrix[r][c]);
                
                if(st.size()>=2)
                    return false;
                
                r++;
                c++;
            }   
        }
        
        return true;
        
    }
};