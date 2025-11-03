class LRUCache {
public:
    struct Node
    {
        int key,val;
        Node *prev;
        Node *next;
        
        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };
    int cap;
    unordered_map<int,Node*>mp;
    
    Node *head = new Node(-1,0);
    Node *tail = new Node(-1,0);    
    
    LRUCache(int c) {
        cap=c;
        
        head->next = head->prev = tail;
        tail->next = tail->prev = head;
    }
    
    int get(int key) {
        
        if(mp.count(key)==0)
            return -1;
        
        Node *temp = mp[key];
        delete_node(temp);
        
        add_at_tail(temp);
        return temp->val;
    }
    
    void delete_at_head()
    {
        Node *curr = head->next;

        head->next = curr->next;
        curr->next->prev = head;

        mp.erase(curr->key);
        delete(curr);
        
        return;
    }
    
    void delete_node(Node *temp)
    {
        Node *p = temp->prev, *n = temp->next , *temp2 = tail->prev;
        
        p->next = n;
        n->prev = p;
        
    }
    
    void add_at_tail(Node *temp)
    {
        Node *temp2 = tail->prev;
        
        temp->next = tail;
        temp->prev = temp2;

        temp2->next = temp;
        tail->prev = temp;
    }
    
    void put(int key, int value) {
        
        if(mp.count(key)==1)
        delete_node(mp[key]);        
        
        Node *temp = new Node(key,value);           
        mp[key] = temp;

        add_at_tail(temp);

        if(mp.size()>cap)
        delete_at_head();

        return;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */