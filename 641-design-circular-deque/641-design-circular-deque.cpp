class MyCircularDeque {
public:
     struct Node{
        
        Node *prev,*next;
        int val;
        
        Node(int x){
            prev = next = NULL;
            val = x;
        }
    };
    
    int sz,cap;
    Node *head , *tail;
    
    MyCircularDeque(int k) {
        
        head = new Node(-1);
        tail = new Node(-1);
        
        head->next = tail;
        tail->prev = head;
        
        cap =0;
        sz = k;
    }
    
    bool insertFront(int value) {
        
        if(cap == sz)
            return false;
        
        Node* temp = new Node(value);
        
        
        temp->next = head->next;
        head->next->prev = temp;
        temp->prev = head;
        head->next = temp;
        
        cap++;
        
        return true;
    }
    
    bool insertLast(int value) {
        
        if(cap == sz)
            return false;
        
        Node* temp = new Node(value);
        
        temp->prev = tail->prev;
        tail->prev->next = temp;
        temp->next = tail;
        tail->prev = temp;
        
        cap++;
        return true;
        
    }
    
    bool deleteFront() {
        
        if(cap == 0)
            return false;
        
        cap--;
        
        Node *temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        
        delete(temp);
        
        return true;
        
    }
    
    bool deleteLast() {
        if(cap == 0)
            return false;
        
        cap--;
        
        Node *temp = tail->prev;
        temp->prev->next = tail;
        tail->prev = temp->prev;
        
        delete(temp);
        
        return true;
        
    }
    
    int getFront() {
        
        if(cap==0 or head->next == tail)
            return -1;
        
        return head->next->val;
    }
    
    int getRear() {
        
         if(cap==0 or tail->prev == head)
            return -1;
        
        return tail->prev->val;
    }
    
    bool isEmpty() {
        return (cap == 0) ? true : false;
    }
    
    bool isFull() {
        return (cap == sz) ? true : false;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */