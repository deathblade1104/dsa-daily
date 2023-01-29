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
    int minFreq,maxSize,cap;
    unordered_map<int,Node*>keyMap;
    unordered_map<int,array<Node*,2>>freqMap;
    
    LFUCache(int capacity) {
        maxSize = 0;
        minFreq = 1;
        cap = capacity;
    }
    
    bool isListEmpty(int f){
        
        Node *head = freqMap[f][0],*tail = freqMap[f][1];
        
        return((head->next == tail) and (tail->prev == head));
    }
    
    void initFreqInFreqMap(int f){
        
        if(freqMap.count(f) == 0){
            
            Node *head = new Node();
            Node *tail = new Node();
            
            tail->prev = head;
            head->next = tail;
            
            freqMap[f] = {head,tail};
        }
        
        return;
    }
    
    void increaseNodeFreq(Node *currNode){
        
        Node *prevNode = currNode->prev;
        Node *nextNode = currNode->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        
        currNode->next=currNode->prev=NULL;
        
        currNode->freq++;
        
        if(isListEmpty(currNode->freq - 1)){
            
            if(minFreq == currNode->freq-1)
                minFreq = currNode->freq;
            
            freqMap.erase(currNode->freq - 1);
        }
        
    }
    
    void deleteInFreqMapFront(int f){
        
        
        Node *head = freqMap[f][0];
        Node *firstNode = head->next;
        
        head->next = firstNode->next;
        firstNode->next->prev = head;
        
        keyMap.erase(firstNode->key);
        
        if(isListEmpty(firstNode->freq)){
            minFreq = 1;
            freqMap.erase(firstNode->freq);
        }
        
        delete(firstNode);
        
//         cout<<"After Deleting FreqMap becomes : "<<endl;
            
//                 for(auto&itr : freqMap){

//                     cout<<"For Freq : "<<itr.first<<endl;

//                     Node *head = itr.second[0],*tail = itr.second[1];

//                     Node *curr = head->next;

//                     while(curr!=tail){

//                         cout<<"( "<<curr->key<<" , "<<curr->value<<" ) "<<" ---> ";
//                         curr=curr->next;
//                     }
//                     cout<<endl;
//                 }
        
        return;
    }
    
    void addInFreqMapBack(Node *newNode){
        
        int f = newNode->freq;
        
        initFreqInFreqMap(f);
        
        Node *tail = freqMap[f][1];
        Node *secondLast = tail->prev;
        
        secondLast->next = newNode;
        newNode->prev= secondLast;
        newNode->next = tail;
        tail->prev= newNode;
        
//          cout<<"After Adding FreqMap becomes : "<<endl;
            
//         for(auto&itr : freqMap){

//             cout<<"For Freq : "<<itr.first<<endl;

//             Node *head = itr.second[0],*tail = itr.second[1];

//             Node *curr = head->next;

//             while(curr!=tail){

//                 cout<<"( "<<curr->key<<" , "<<curr->value<<" ) "<<" ---> ";
//                 curr=curr->next;
//             }
//             cout<<endl;
//         }
        
        return;
    }
    
    int get(int key) {
        
        if(keyMap.count(key)==0 or !cap)
            return -1;
        
        //cout<<" Getting value for : "<<key<<endl;
        
        increaseNodeFreq(keyMap[key]);
        addInFreqMapBack(keyMap[key]);
        
        //cout<<endl<<endl;
        return keyMap[key]->value;
    }
    
    void put(int key, int value) {
        
        if(cap == 0)
            return;
        
        //cout<<" Putting "<<key<<" : "<<value<<endl;
        
        if(keyMap.count(key)==1){
            
            keyMap[key]->value = value;
            increaseNodeFreq(keyMap[key]);
            addInFreqMapBack(keyMap[key]);
        }
        
        else{
            
            if(maxSize == cap){
                deleteInFreqMapFront(minFreq);
                maxSize--;
            }
            
            Node *newNode = new Node(key,value,1);
            keyMap[key] = newNode;
            
            //cout<<key<<" --> "<<keyMap[key]->value<<endl;
            
            addInFreqMapBack(newNode);
            minFreq = 1;
            
           
            
            maxSize++;
        }
        
        //cout<<endl;
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */