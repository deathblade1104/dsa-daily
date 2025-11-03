/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
     Node *DFS(Node *x, unordered_map<Node*,Node*>&mp)
     {
         if(!x)
             return x;
         
         if(mp.count(x))
             return mp[x];
         
         mp[x] = new Node(x->val);
        for (Node *y : x->neighbors)
            mp[x]->neighbors.push_back(DFS(y,mp));
        return mp[x];
     }
    
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        return DFS(node,mp);
    }
};