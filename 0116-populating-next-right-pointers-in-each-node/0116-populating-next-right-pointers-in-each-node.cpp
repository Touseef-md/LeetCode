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
        if(root==NULL){
            return root;
        }
        queue<Node*> q;
        Node* temp=new Node(-100000);
        q.push(root);
        q.push(temp);
        Node* temp2;
        while(q.size()>1){
            temp2=q.front();
            q.pop();
            if(temp2->val==-100000){
                q.push(temp2);
                continue;
            }
            if(q.front()->val==-100000){
                temp2->next=NULL;
            }
            else{
                temp2->next=q.front();
            }
            if(temp2->left)
                q.push(temp2->left);
            if(temp2->right)
                q.push(temp2->right);
            
        }
        return root;
    }
};