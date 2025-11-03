// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inOrder(Node *root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


 // } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
// return the head of the DLL and remove those node from the tree as well.
bool isLeaf(Node *root)
{
    return(!root->left and !root->right);
}

void get_leaves(Node *root, Node *par, bool isLeft , queue<Node*>&q)
{
    if(!root)
    return;
    
    if(isLeaf(root))
    {
        q.push(root);
        
        if(isLeft)
        par->left=NULL;
        else
        par->right=NULL;
        
        return;
    }
    
    get_leaves(root->left,root,true,q);
    get_leaves(root->right,root,false,q);
}
Node * convertToDLL(Node *root){
    // add code here.
    if(isLeaf(root))
    return root;
    
    queue<Node*>q;
    get_leaves(root->left,root,true,q);
    get_leaves(root->right,root,false,q);
    
    Node *head= new Node(-1);
    Node *curr= head;
    
    while(q.size()>0)
    {
       Node *temp=q.front();
       q.pop();
       
       curr->right=temp;
       temp->left=curr;
       curr=curr->right;
    }
    
    
    Node *h1=head->right;
    head->right=NULL;
    h1->left=NULL;
    
    return h1;
    
    
    
}

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Node* head = convertToDLL(root);
        inOrder(root);
        cout << "\n";
        Node *curr = head, *last = head;
        while (curr) {
            cout << curr->data << " ";
            last = curr;
            curr = curr->right;
        }
        cout << "\n";
        curr = last;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->left;
        }
        cout << "\n";
    }
    return 0;
}

  // } Driver Code Ends