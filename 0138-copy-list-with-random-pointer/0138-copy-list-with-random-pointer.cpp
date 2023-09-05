/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* temp=head;
        unordered_map<Node*,Node*> mp;
        Node* copiedHead;
        while(temp){
            Node* newNode=new Node(temp->val);
            mp[temp]=newNode;
            if(temp==head){
             copiedHead=newNode;   
            }
            temp=temp->next;
        }
        temp=head;
        while(temp){
            Node* copied=mp[temp];
            Node* to=temp->next;
            Node* pointTo=mp[to];
            copied->next=pointTo;
            if(temp->random==NULL){
                copied->random=NULL;
            }
            else{
                Node* randomPointTo=mp[temp->random];
                copied->random=randomPointTo;
            }
            temp=temp->next;
        }
        return copiedHead;
    }
};