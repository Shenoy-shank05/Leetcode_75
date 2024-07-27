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
    ListNode* oddEvenList(ListNode* head) {
       if(head==NULL || head->next==NULL){return head;}
        ListNode* even=head->next;
        ListNode* odd_temp=head;
        ListNode* even_temp=head->next;
        if( even_temp->next==NULL){ return head;}

        ListNode* temp=even_temp->next;
        even_temp->next=NULL;
        odd_temp->next=NULL;
        int chance=1;
        while(temp!=NULL){
            if(chance){
                ListNode* t=temp->next;
                odd_temp->next=temp;
                temp->next=NULL;
               odd_temp=odd_temp->next;
               temp=t;
               chance=0;
            }
            else{
                ListNode* t=temp->next;
                even_temp->next=temp;
                temp->next=NULL;
                even_temp=even_temp->next;
                temp=t;
                chance=1;
            }

        }
        odd_temp->next=even;
        return head;

    }
};