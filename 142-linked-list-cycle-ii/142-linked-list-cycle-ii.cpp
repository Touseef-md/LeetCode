/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return NULL;
        fast=head->next->next;
        slow=slow->next;
        while(fast->next!=NULL&&fast->next->next!=NULL&&slow!=fast){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next==NULL||fast->next->next==NULL)
            return NULL;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};