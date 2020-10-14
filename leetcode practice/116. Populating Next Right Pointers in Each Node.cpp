/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL)
            return root;
        
        Node * t=NULL;
        Node * head=root;
        queue<Node* > q;
        q.push(root);
        q.push(t);
        
        while(!q.empty())
        {
            Node* a=q.front();
            q.pop();
            
            if(a==NULL)
            {
                if(!q.empty())
                    q.push(t);
                
                continue;
            }
            
            a->next=q.front();
            if(a->left)
                q.push(a->left);
            if(a->right)
                q.push(a->right);
        }
        
        return head;
    }
};
