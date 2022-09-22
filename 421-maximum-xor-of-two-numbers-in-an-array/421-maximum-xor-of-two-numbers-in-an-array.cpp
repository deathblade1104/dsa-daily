class Solution {
public:
     struct TrieNode{
    
        TrieNode *children[2];
        TrieNode(){
            children[0] = children[1] = NULL;
        }
    };
    
    TrieNode *root;
    
    void insert(int num){
        
        TrieNode *curr = root;
        for(int j=31;j>=0;j--){
            
            bool x  = (num & (1<<j)) ? true : false ;
            
            if(curr->children[x] == NULL)
                curr->children[x] = new TrieNode(); 
            
            curr = curr->children[x];
        }
        return;
    }
    
    int findMax(int num){
        
        TrieNode *curr = root;
        int ans=0;
        
        for(int j=31;j>=0;j--){
            
             bool x  = (num & (1<<j)) ? true : false ;
            
            if(curr->children[!x]){
                ans |= (1<<j);
                curr = curr->children[!x] ;
            }
            
            else
            curr = curr->children[x];
        }
        return ans;
        
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        root = new TrieNode();
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            insert(nums[i]);
            ans = max(ans,findMax(nums[i]));
        }
            
        return ans;
        
        
    }
};