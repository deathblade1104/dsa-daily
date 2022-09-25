class MyCircularQueue {
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
    
    MyCircularQueue(int k) {
        
        head = new Node(-1);
        tail = new Node(-1);
        
        head->next = tail;
        tail->prev = head;
        
        cap =0;
        sz = k;
    }
    
    bool enQueue(int value) {
        
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
    
    bool deQueue() {
        
        if(cap == 0)
            return false;
        
        cap--;
        
        Node *temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        
        delete(temp);
        
        return true;
        
    }
    
    int Front() {
        
        if(head->next == tail or cap==0)
            return -1;
        
        return head->next->val;
    }
    
    int Rear() {
        
        if(tail->prev == head or cap==0)
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */