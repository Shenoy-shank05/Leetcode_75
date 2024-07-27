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
    int pairSum(ListNode* head) {
        stack<ListNode*> s;
        ListNode* temp=head;
        while(temp!=NULL){
            s.push(temp);
            temp=temp->next;
        }
        int length=s.size()/2;
        int ans=INT_MIN;
        temp=head;
        while(s.size()!=length){
          
            ans=max(ans,temp->val + s.top()->val);           
            s.pop();
            temp=temp->next;

        }
        return ans;
        
    }
};