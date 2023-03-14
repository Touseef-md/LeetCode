/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size(),val;
        if(n==0)
            return NULL;
        ListNode* temp=NULL;
        ListNode* result=new ListNode(-1);
        // result->next=prop;
        ListNode* prop=result;
        vector<ListNode*> ptrs(n);
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<n;i++){
            ptrs[i]=lists[i];
            if(lists[i]!=NULL)
                pq.push({lists[i]->val,lists[i]});
        }
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            val=it.first;
            temp=it.second;
            temp=temp->next;
            prop->next=new ListNode(val);
            prop=prop->next;
            if(temp!=NULL)
                pq.push({temp->val,temp});
        }
        return result->next;
    }
};