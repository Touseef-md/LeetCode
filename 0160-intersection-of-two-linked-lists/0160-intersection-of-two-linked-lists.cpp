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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        unordered_map<ListNode*,int> mp;
        while(ptr1){
            mp[ptr1]++;
            ptr1=ptr1->next;
        }
        while(ptr2){
            auto it = mp.find(ptr2);
            if(it != mp.end()){
                return it->first;
            }
            ptr2=ptr2->next;
        }
        return NULL;
//         while(ptr1!=ptr2){
//             if(ptr1->next == NULL){
//                 ptr1=headB;
//                 ptr2=ptr2->next;
//                 continue;
//             }
//             if(ptr2->next == NULL){
//                 ptr2=headA;
//                 ptr1= ptr1->next;
//                 continue;
//             }
//             ptr1= ptr1->next;
//             ptr2= ptr2->next;
            
//         }
        return ptr1;
    }
};