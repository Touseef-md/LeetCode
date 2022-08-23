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
    bool isPalindrome(ListNode* head) {
        string st="";
        ListNode* temp=head;
        while(temp!=NULL){
            st+=to_string(temp->val);
            temp=temp->next;
        }
        int i=0,j=st.length()-1;
        while(i<=j){
            if(st[i]!=st[j])
                return false;
            i++;
            j--;
        }
        return true;
        
        
        
//         Below is the S.C:O(1) logic
        // int len=0;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //  temp=temp->next;
        //     len++;
        // }
        // int i=1,j=len-1;
        // temp=head;
        // while(i<(len+1)/2){
        //     i++;
        //     temp=temp->next;
        // }
        // ListNode* nxt=temp->next;
        // ListNode* nxtnxt;
        // ListNode* end;
        // if(nxt->next!=NULL){
        //     nxtnxt=nxt->next;
        //     while(nxt!=NULL){
        //         cout<<temp->val<<endl;
        //         cout<<"NXT val "<<nxt->val<<endl;
        //         nxt->next=temp;
        //         temp=nxt;
        //         nxt=nxtnxt;
        //         if(nxt==NULL){
        //             cout<<"END is temp"<<endl;
        //             end=temp;
        //             break;
        //         }
        //         cout<<"AFTER end "<<endl;
        //         if(nxtnxt!=nullptr) {
        //             nxtnxt=nxtnxt->next;
        //         }
        //     }
        //     cout << 1 << endl;
        // }
        // else{
        //     cout<<"ER"<<endl;
        //     nxt->next=temp;
        //     // cout<<"ERR"<<endl;
        //     end=nxt;
        // }
        // // cout<<"RSE"<<endl;
        // // i=0;
        // // temp=head;
        // // while(i<=j){
        // //     cout<<"I and J  "<<i<<"  "<<j<<endl;
        // //     cout<<"TEMP  "<<temp->val<<endl;
        // //         cout<<"END "<<end->val<<endl;
        // //     if((temp->val)!=(end->val))
        // //         return false;
        // //     cout<<"CHEcK"<<endl;
        // //     temp=temp->next;
        // //     cout<<"BET"<<endl;
        // //     end=end->next;
        // //     cout<<"LAST"<<endl;
        // //     i++;
        // //     j--;
        // //     cout<<"WHILE End "<<i<<"  "<<j<<endl;
        // // }
        // // cout<<"OUT"<<endl;
        // return true;
    }
};