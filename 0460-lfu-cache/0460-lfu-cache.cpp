struct Node{

    int key;
    int value;
    int freq;
    Node *prev,*next;

    Node(int k=-1,int val=-1,int f=-1){
        key = k;
        value = val;
        freq = f;

        prev=NULL;
        next=NULL;
    }
};

class LFUCache {
public:
    
    int cap;
    unordered_map<int,Node*>keyMap;
    map<int,array<Node*,2>>freqMap;
    
    bool isListEmpty(int f){
        
        Node *head = freqMap[f][0];
        Node *tail = freqMap[f][1];
        
        return((head->next == tail) and (tail->prev == head));
    }
    
    void initFreqInFreqMap(int f){
        
        if(freqMap.count(f) == 1)
        return;
        
        Node *head = new Node();
        Node *tail = new Node();

        tail->prev = head;
        head->next = tail;

        freqMap[f] = {head,tail};
        
        return;
    }
    
    void delete_at_head()
    {
        
        Node *head = freqMap.begin()->second[0];
        Node *curr = head->next;

        head->next = curr->next;
        curr->next->prev = head;

        keyMap.erase(curr->key);
        delete(curr);
        
        if(isListEmpty(freqMap.begin()->first)){
            freqMap.erase(freqMap.begin()->first);
        }
        
        return;
    }
    
    void delete_node(Node *temp)
    {
        Node *p = temp->prev, *n = temp->next;
        
        p->next = n;
        n->prev = p;
        
        temp->prev=temp->next = NULL;
        
        if(isListEmpty(temp->freq)){
            freqMap.erase(temp->freq);
        }
    }
    
    void add_at_tail(Node *temp)
    {
        initFreqInFreqMap(temp->freq);
        
        Node *tail = freqMap[temp->freq][1];
        Node *temp2 = tail->prev;
        
        temp->next = tail;
        temp->prev = temp2;

        temp2->next = temp;
        tail->prev = temp;
        
        return;
    }
    

    LFUCache(int capacity) {
        cap = capacity;
        //minFreq = 1;
    }
    
    int get(int key) {
        
        if(keyMap.count(key)==0 or cap==0)
            return -1;
        
        Node *temp = keyMap[key];
        delete_node(temp);
        
        temp->freq++;
        add_at_tail(temp);
        
        return temp->value;
        
    }
    
    void put(int key, int value) {
        
        if(cap == 0)
            return;
        
        Node *temp;
        
        if(keyMap.count(key)){
            temp = keyMap[key];
            delete_node(temp);
            temp->value = value;
            temp->freq++;
        }
        
        else {
            
            if(keyMap.size()>=cap)
                delete_at_head();
            
            temp = new Node(key,value,1);
            keyMap[key] = temp;
            //minFreq = 1;
        }
        
        add_at_tail(temp);
        
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */