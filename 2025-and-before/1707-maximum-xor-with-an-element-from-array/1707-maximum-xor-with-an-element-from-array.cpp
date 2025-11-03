class Solution {
public:
    int msb;
    
    struct BinaryTrie {
        array<BinaryTrie*, 2> children;
        int mini;
        BinaryTrie() {
            children[0] = children[1] = nullptr;
            mini = INT_MAX;
        }
    };
    
    void insert(int& num, BinaryTrie* root) {
        BinaryTrie* curr = root;
        for (int i = msb; i >= 0; i--) {
            bool next = ((1 << i) & num) ? true : false;
            curr->mini = min(curr->mini,num);
            if (curr->children[next] == nullptr) {
                curr->children[next] = new BinaryTrie();
            }
            curr = curr->children[next];
        }
        curr->mini = min(curr->mini,num);
    }
    
    int search(int&num,int&lim,BinaryTrie *root){
        BinaryTrie* curr = root;
        int ans = 0;
        for (int j = msb; j >= 0; j--) {
            int next = (num & (1 << j)) ? 1 : 0;
            
            if (curr->children[!next] and curr->children[!next]->mini<=lim) {
                ans |= (1 << j);
                curr = curr->children[!next];
            } else if(curr->children[next]  and curr->children[next]->mini<=lim) {
                curr = curr->children[next];
            }
            else return -1;
        }
        
        return ans;
    }
    
    int findMsb(int&num){    
        
         for(int i=31;i>=0;i--){
            if((1<<i) & num){
                return i;
            }
        }
        
        return -1;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int>ans;
        BinaryTrie *root = new BinaryTrie();
        msb = 0;
        
        for(int&i : nums){
            msb = max(msb,findMsb(i));
        }
        
        for(auto&q : queries){
            msb = max(msb,findMsb(q[0]));
        }
        
        for(int&i : nums)
            insert(i,root);
        
        for(vector<int>&q : queries){
            ans.push_back(search(q[0],q[1],root));
        }
        
        
        return ans;
    }
};