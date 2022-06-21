// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    public:
    struct Node{
        int k,v;
        Node *next,*prev;
        
        Node(int key,int val)
        {
            k= key;
            v = val;
            prev=next = NULL;
        }
    };
    
    int sz;
    unordered_map<int,Node*>mp;
    Node *head,*tail;
    
    LRUCache(int cap)
    {
        sz = cap;
        head = new Node(-1001,0);
        tail = new Node(1001,-1);
        
        head->next = tail;
        tail->prev = head;
    }
    
    
    int get(int key)
    {
        if(mp.count(key)==0)
        return -1;
        
        int res = mp[key]->v;
        delete_node(mp[key]);
        insert_at_end(mp[key]);
        return res;
    }
    
    void insert_at_end(Node *curr)
    {
        curr->prev = tail->prev;
        tail->prev->next = curr;
        tail->prev = curr;
        curr->next = tail;
    }
    
    void delete_node(Node *curr)
    {
        curr->prev->next= curr->next;
        curr->next->prev = curr->prev;
    }
    
    void delete_at_head()
    {
        Node *curr = head->next;
        curr->next->prev= head;
        head->next = curr->next;
    }

    void set(int key, int value)
    {
        if(mp.count(key)==1)
        {
            mp[key]->v= value;
            delete_node(mp[key]);
        }
        
        else
        {
            if(mp.size()>=sz)
            {
                int k = head->next->k;
                mp.erase(k);
                delete_at_head();
            }
            
            Node *temp = new Node(key,value);
            mp[key]=temp;
        }
        
        insert_at_end(mp[key]);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends