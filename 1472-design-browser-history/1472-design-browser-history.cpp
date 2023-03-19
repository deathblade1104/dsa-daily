class BrowserHistory {
    struct ListNode{
        
        string url;
        ListNode *prev, *next;
        
        ListNode(string str){
            url = str;
            prev = NULL;
            next = NULL;
        }
    };
    
public:
    ListNode *head,*curr;
    BrowserHistory(string homepage) {
        head = new ListNode(homepage);
        curr = head;
    }
    
    void visit(string url) {
        
        ListNode *newVisit = new ListNode(url);
        
        if(curr->next){
            ListNode *temp = curr->next;
            curr->next = NULL;
            temp->prev = NULL;
            
            deleteList(temp);
        }
        
        curr->next = newVisit;
        newVisit->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        
        while(steps-- and curr!=head){
            
            curr = curr->prev;
        }
        
        return curr->url;
    }
    
    string forward(int steps) {
        
        while(steps-- and curr->next){
            
            curr = curr->next;
        }
        
        return curr->url;
    }
    
    void deleteList(ListNode *curr){
        
        while(curr){
            
            ListNode *temp = curr;
            curr= curr->next;
            
            delete(temp);
        }
        
        return;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */